static T_1
F_1 ( unsigned short V_1 , unsigned int V_2 )
{
int V_3 = V_4 ;
if ( V_2 & V_5 )
V_3 |= V_6 ;
if ( V_1 & V_7 )
V_3 |= V_8 ;
if ( V_1 & V_9 )
V_3 |= V_10 ;
if ( ( V_1 & V_9 ) && ( V_2 & V_11 ) )
V_3 |= V_12 ;
if ( V_1 & V_13 )
V_3 |= V_14 ;
return V_3 ;
}
static T_1
F_2 ( unsigned short V_1 , T_1 V_2 )
{
T_1 V_3 = 0 ;
if ( V_1 & V_7 )
V_3 |= V_8 ;
if ( V_1 & V_9 )
V_3 |= V_10 ;
if ( ( V_1 & V_9 ) && ( V_2 & V_11 ) )
V_3 |= V_12 ;
if ( V_1 & V_13 )
V_3 |= V_14 ;
return V_3 ;
}
static void
F_3 ( T_1 V_1 , unsigned short * V_15 , unsigned int V_2 )
{
T_1 V_16 = V_10 ;
if ( V_2 & V_11 )
V_16 |= V_12 ;
* V_15 = 0 ;
if ( ( V_1 & V_8 ) == V_8 )
* V_15 |= V_7 ;
if ( ( V_1 & V_16 ) == V_16 )
* V_15 |= V_9 ;
if ( ( V_1 & V_14 ) == V_14 )
* V_15 |= V_13 ;
}
int
F_4 ( struct V_17 * V_18 , struct V_19 * V_19 ,
struct V_20 * * V_21 )
{
struct V_22 * V_22 = V_19 -> V_23 ;
int error = 0 ;
struct V_24 * V_25 = NULL , * V_26 = NULL ;
unsigned int V_2 = 0 ;
int V_27 = 0 ;
V_25 = F_5 ( V_22 , V_28 ) ;
if ( ! V_25 )
V_25 = F_6 ( V_22 -> V_29 , V_30 ) ;
if ( F_7 ( V_25 ) )
return F_8 ( V_25 ) ;
V_27 += 2 * V_25 -> V_31 ;
if ( F_9 ( V_22 -> V_29 ) ) {
V_2 = V_11 ;
V_26 = F_5 ( V_22 , V_32 ) ;
if ( F_7 ( V_26 ) ) {
error = F_8 ( V_26 ) ;
goto V_33;
}
if ( V_26 )
V_27 += 2 * V_26 -> V_31 ;
}
* V_21 = F_10 ( F_11 ( V_27 ) , V_30 ) ;
if ( * V_21 == NULL ) {
error = - V_34 ;
goto V_35;
}
( * V_21 ) -> V_36 = 0 ;
F_12 ( V_25 , * V_21 , V_2 & ~ V_37 ) ;
if ( V_26 )
F_12 ( V_26 , * V_21 , V_2 | V_37 ) ;
V_35:
F_13 ( V_26 ) ;
V_33:
F_13 ( V_25 ) ;
return error ;
}
static void
F_14 ( struct V_24 * V_21 , struct V_38 * V_39 )
{
struct V_40 * V_41 , * V_42 ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_3 = 07 ;
V_42 = V_21 -> V_43 + V_21 -> V_31 ;
F_15 (pa, acl, pe) {
switch ( V_41 -> V_44 ) {
case V_45 :
V_39 -> V_46 = V_41 -> V_47 ;
break;
case V_48 :
V_39 -> V_49 = V_41 -> V_47 ;
break;
case V_50 :
V_39 -> V_51 |= V_41 -> V_47 ;
break;
case V_52 :
V_39 -> V_53 |= V_41 -> V_47 ;
break;
case V_54 :
V_39 -> V_55 = V_41 -> V_47 ;
break;
case V_56 :
V_39 -> V_3 = V_41 -> V_47 ;
break;
}
}
V_39 -> V_51 &= V_39 -> V_3 ;
V_39 -> V_49 &= V_39 -> V_3 ;
V_39 -> V_53 &= V_39 -> V_3 ;
}
static void
F_12 ( struct V_24 * V_25 , struct V_20 * V_21 ,
unsigned int V_2 )
{
struct V_40 * V_41 , * V_57 ;
struct V_58 * V_59 ;
struct V_38 V_39 ;
unsigned short V_60 ;
int V_61 = ( ( V_2 & V_37 ) ?
V_62 | V_63 : 0 ) ;
F_16 ( V_25 -> V_31 < 3 ) ;
F_14 ( V_25 , & V_39 ) ;
V_41 = V_25 -> V_43 ;
V_59 = V_21 -> V_64 + V_21 -> V_36 ;
V_60 = ~ V_39 . V_46 ;
V_60 &= V_39 . V_51 | V_39 . V_49 | V_39 . V_53 | V_39 . V_55 ;
if ( V_60 ) {
V_59 -> type = V_65 ;
V_59 -> V_66 = V_61 ;
V_59 -> V_67 = F_2 ( V_60 , V_2 ) ;
V_59 -> V_68 = V_69 ;
V_59 ++ ;
V_21 -> V_36 ++ ;
}
V_59 -> type = V_70 ;
V_59 -> V_66 = V_61 ;
V_59 -> V_67 = F_1 ( V_41 -> V_47 , V_2 | V_5 ) ;
V_59 -> V_68 = V_69 ;
V_59 ++ ;
V_21 -> V_36 ++ ;
V_41 ++ ;
while ( V_41 -> V_44 == V_50 ) {
V_60 = ~ ( V_41 -> V_47 & V_39 . V_3 ) ;
V_60 &= V_39 . V_53 | V_39 . V_49 | V_39 . V_55 ;
if ( V_60 ) {
V_59 -> type = V_65 ;
V_59 -> V_66 = V_61 ;
V_59 -> V_67 = F_2 ( V_60 , V_2 ) ;
V_59 -> V_68 = V_71 ;
V_59 -> V_72 = V_41 -> V_73 ;
V_59 ++ ;
V_21 -> V_36 ++ ;
}
V_59 -> type = V_70 ;
V_59 -> V_66 = V_61 ;
V_59 -> V_67 = F_1 ( V_41 -> V_47 & V_39 . V_3 ,
V_2 ) ;
V_59 -> V_68 = V_71 ;
V_59 -> V_72 = V_41 -> V_73 ;
V_59 ++ ;
V_21 -> V_36 ++ ;
V_41 ++ ;
}
V_57 = V_41 ;
V_59 -> type = V_70 ;
V_59 -> V_66 = V_61 ;
V_59 -> V_67 = F_1 ( V_39 . V_49 , V_2 ) ;
V_59 -> V_68 = V_74 ;
V_59 ++ ;
V_21 -> V_36 ++ ;
V_41 ++ ;
while ( V_41 -> V_44 == V_52 ) {
V_59 -> type = V_70 ;
V_59 -> V_66 = V_61 | V_75 ;
V_59 -> V_67 = F_1 ( V_41 -> V_47 & V_39 . V_3 ,
V_2 ) ;
V_59 -> V_68 = V_71 ;
V_59 -> V_76 = V_41 -> V_77 ;
V_59 ++ ;
V_21 -> V_36 ++ ;
V_41 ++ ;
}
V_41 = V_57 ;
V_60 = ~ V_39 . V_49 & V_39 . V_55 ;
if ( V_60 ) {
V_59 -> type = V_65 ;
V_59 -> V_66 = V_61 ;
V_59 -> V_67 = F_2 ( V_60 , V_2 ) ;
V_59 -> V_68 = V_74 ;
V_59 ++ ;
V_21 -> V_36 ++ ;
}
V_41 ++ ;
while ( V_41 -> V_44 == V_52 ) {
V_60 = ~ ( V_41 -> V_47 & V_39 . V_3 ) ;
V_60 &= V_39 . V_55 ;
if ( V_60 ) {
V_59 -> type = V_65 ;
V_59 -> V_66 = V_61 | V_75 ;
V_59 -> V_67 = F_2 ( V_60 , V_2 ) ;
V_59 -> V_68 = V_71 ;
V_59 -> V_76 = V_41 -> V_77 ;
V_59 ++ ;
V_21 -> V_36 ++ ;
}
V_41 ++ ;
}
if ( V_41 -> V_44 == V_56 )
V_41 ++ ;
V_59 -> type = V_70 ;
V_59 -> V_66 = V_61 ;
V_59 -> V_67 = F_1 ( V_41 -> V_47 , V_2 ) ;
V_59 -> V_68 = V_78 ;
V_21 -> V_36 ++ ;
}
static bool
F_17 ( struct V_40 * V_79 , struct V_40 * V_80 )
{
if ( V_79 -> V_44 != V_80 -> V_44 )
return V_79 -> V_44 > V_80 -> V_44 ;
if ( V_79 -> V_44 == V_50 )
return F_18 ( V_79 -> V_73 , V_80 -> V_73 ) ;
if ( V_79 -> V_44 == V_52 )
return F_19 ( V_79 -> V_77 , V_80 -> V_77 ) ;
return false ;
}
static void
F_20 ( struct V_24 * V_25 , int V_81 , int V_82 ) {
int V_83 = 0 , V_84 ;
struct V_40 V_85 ;
while ( ! V_83 ) {
V_83 = 1 ;
for ( V_84 = V_81 ; V_84 < V_82 ; V_84 ++ ) {
if ( F_17 ( & V_25 -> V_43 [ V_84 ] ,
& V_25 -> V_43 [ V_84 + 1 ] ) ) {
V_83 = 0 ;
V_85 = V_25 -> V_43 [ V_84 ] ;
V_25 -> V_43 [ V_84 ] = V_25 -> V_43 [ V_84 + 1 ] ;
V_25 -> V_43 [ V_84 + 1 ] = V_85 ;
}
}
}
}
static void
F_21 ( struct V_24 * V_25 )
{
int V_84 , V_86 ;
if ( ! V_25 || V_25 -> V_31 <= 4 )
return;
V_84 = 1 ;
while ( V_25 -> V_43 [ V_84 ] . V_44 == V_50 )
V_84 ++ ;
F_20 ( V_25 , 1 , V_84 - 1 ) ;
F_16 ( V_25 -> V_43 [ V_84 ] . V_44 != V_48 ) ;
V_86 = ++ V_84 ;
while ( V_25 -> V_43 [ V_86 ] . V_44 == V_52 )
V_86 ++ ;
F_20 ( V_25 , V_84 , V_86 - 1 ) ;
return;
}
static int
F_22 ( struct V_87 * V_88 , int V_89 )
{
int V_90 ;
memset ( V_88 , 0 , sizeof( struct V_87 ) ) ;
V_88 -> V_91 = 1 ;
V_90 = sizeof( struct V_92 )
+ V_89 * sizeof( struct V_93 ) ;
V_88 -> V_51 = F_23 ( V_90 , V_30 ) ;
if ( ! V_88 -> V_51 )
return - V_34 ;
V_88 -> V_53 = F_23 ( V_90 , V_30 ) ;
if ( ! V_88 -> V_53 ) {
F_24 ( V_88 -> V_51 ) ;
return - V_34 ;
}
return 0 ;
}
static void
F_25 ( struct V_87 * V_88 ) {
F_24 ( V_88 -> V_51 ) ;
F_24 ( V_88 -> V_53 ) ;
}
static inline void F_26 ( struct V_87 * V_88 , struct V_94 * V_95 )
{
V_88 -> V_3 . V_96 |= V_95 -> V_96 ;
}
static inline int F_27 ( T_1 V_3 , int V_97 )
{
if ( V_3 & ( V_98 | V_99 ) )
return - V_100 ;
if ( ! V_97 )
return 0 ;
if ( V_3 & ( V_101 | V_102 ) )
return - V_100 ;
return 0 ;
}
static struct V_24 *
F_28 ( struct V_87 * V_88 , unsigned int V_2 )
{
struct V_40 * V_103 ;
struct V_24 * V_25 ;
int V_104 ;
int V_84 , error = 0 ;
if ( V_88 -> V_91 && ( V_2 & V_37 ) )
return NULL ;
if ( ! V_88 -> V_51 -> V_105 && ! V_88 -> V_53 -> V_105 )
V_104 = 3 ;
else
V_104 = 4 + V_88 -> V_51 -> V_105 + V_88 -> V_53 -> V_105 ;
V_25 = F_29 ( V_104 , V_30 ) ;
if ( ! V_25 )
return F_30 ( - V_34 ) ;
V_103 = V_25 -> V_43 ;
V_103 -> V_44 = V_45 ;
error = F_27 ( V_88 -> V_46 . V_60 , 1 ) ;
if ( error )
goto V_106;
F_3 ( V_88 -> V_46 . V_96 , & V_103 -> V_47 , V_2 ) ;
for ( V_84 = 0 ; V_84 < V_88 -> V_51 -> V_105 ; V_84 ++ ) {
V_103 ++ ;
V_103 -> V_44 = V_50 ;
error = F_27 ( V_88 -> V_51 -> V_64 [ V_84 ] . V_107 . V_60 , 0 ) ;
if ( error )
goto V_106;
F_3 ( V_88 -> V_51 -> V_64 [ V_84 ] . V_107 . V_96 ,
& V_103 -> V_47 , V_2 ) ;
V_103 -> V_73 = V_88 -> V_51 -> V_64 [ V_84 ] . V_108 ;
F_26 ( V_88 , & V_88 -> V_51 -> V_64 [ V_84 ] . V_107 ) ;
}
V_103 ++ ;
V_103 -> V_44 = V_48 ;
error = F_27 ( V_88 -> V_49 . V_60 , 0 ) ;
if ( error )
goto V_106;
F_3 ( V_88 -> V_49 . V_96 , & V_103 -> V_47 , V_2 ) ;
F_26 ( V_88 , & V_88 -> V_49 ) ;
for ( V_84 = 0 ; V_84 < V_88 -> V_53 -> V_105 ; V_84 ++ ) {
V_103 ++ ;
V_103 -> V_44 = V_52 ;
error = F_27 ( V_88 -> V_53 -> V_64 [ V_84 ] . V_107 . V_60 , 0 ) ;
if ( error )
goto V_106;
F_3 ( V_88 -> V_53 -> V_64 [ V_84 ] . V_107 . V_96 ,
& V_103 -> V_47 , V_2 ) ;
V_103 -> V_77 = V_88 -> V_53 -> V_64 [ V_84 ] . V_109 ;
F_26 ( V_88 , & V_88 -> V_53 -> V_64 [ V_84 ] . V_107 ) ;
}
if ( V_88 -> V_51 -> V_105 || V_88 -> V_53 -> V_105 ) {
V_103 ++ ;
V_103 -> V_44 = V_56 ;
F_3 ( V_88 -> V_3 . V_96 , & V_103 -> V_47 , V_2 ) ;
}
V_103 ++ ;
V_103 -> V_44 = V_54 ;
error = F_27 ( V_88 -> V_55 . V_60 , 0 ) ;
if ( error )
goto V_106;
F_3 ( V_88 -> V_55 . V_96 , & V_103 -> V_47 , V_2 ) ;
return V_25 ;
V_106:
F_13 ( V_25 ) ;
return F_30 ( error ) ;
}
static inline void F_31 ( struct V_94 * V_95 , T_1 V_3 )
{
V_95 -> V_96 |= V_3 & ~ V_95 -> V_60 ;
}
static inline void F_32 ( struct V_94 * V_95 , T_1 V_3 )
{
V_95 -> V_60 |= V_3 & ~ V_95 -> V_96 ;
}
static int F_33 ( struct V_87 * V_88 , T_2 V_108 )
{
struct V_92 * V_110 = V_88 -> V_51 ;
int V_84 ;
for ( V_84 = 0 ; V_84 < V_110 -> V_105 ; V_84 ++ )
if ( F_34 ( V_110 -> V_64 [ V_84 ] . V_108 , V_108 ) )
return V_84 ;
V_110 -> V_105 ++ ;
V_110 -> V_64 [ V_84 ] . V_108 = V_108 ;
V_110 -> V_64 [ V_84 ] . V_107 . V_96 = V_88 -> V_111 . V_96 ;
V_110 -> V_64 [ V_84 ] . V_107 . V_60 = V_88 -> V_111 . V_60 ;
return V_84 ;
}
static int F_35 ( struct V_87 * V_88 , T_3 V_109 )
{
struct V_92 * V_110 = V_88 -> V_53 ;
int V_84 ;
for ( V_84 = 0 ; V_84 < V_110 -> V_105 ; V_84 ++ )
if ( F_36 ( V_110 -> V_64 [ V_84 ] . V_109 , V_109 ) )
return V_84 ;
V_110 -> V_105 ++ ;
V_110 -> V_64 [ V_84 ] . V_109 = V_109 ;
V_110 -> V_64 [ V_84 ] . V_107 . V_96 = V_88 -> V_111 . V_96 ;
V_110 -> V_64 [ V_84 ] . V_107 . V_60 = V_88 -> V_111 . V_60 ;
return V_84 ;
}
static void F_37 ( struct V_92 * V_110 , T_1 V_3 )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < V_110 -> V_105 ; V_84 ++ )
F_32 ( & V_110 -> V_64 [ V_84 ] . V_107 , V_3 ) ;
}
static void F_38 ( struct V_92 * V_110 , T_1 V_3 )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < V_110 -> V_105 ; V_84 ++ )
F_31 ( & V_110 -> V_64 [ V_84 ] . V_107 , V_3 ) ;
}
static void F_39 ( struct V_87 * V_88 ,
struct V_58 * V_59 )
{
T_1 V_3 = V_59 -> V_67 ;
int V_84 ;
V_88 -> V_91 = 0 ;
switch ( F_40 ( V_59 ) ) {
case V_45 :
if ( V_59 -> type == V_70 ) {
F_31 ( & V_88 -> V_46 , V_3 ) ;
} else {
F_32 ( & V_88 -> V_46 , V_3 ) ;
}
break;
case V_50 :
V_84 = F_33 ( V_88 , V_59 -> V_72 ) ;
if ( V_59 -> type == V_70 ) {
F_31 ( & V_88 -> V_51 -> V_64 [ V_84 ] . V_107 , V_3 ) ;
} else {
F_32 ( & V_88 -> V_51 -> V_64 [ V_84 ] . V_107 , V_3 ) ;
V_3 = V_88 -> V_51 -> V_64 [ V_84 ] . V_107 . V_60 ;
F_32 ( & V_88 -> V_46 , V_3 ) ;
}
break;
case V_48 :
if ( V_59 -> type == V_70 ) {
F_31 ( & V_88 -> V_49 , V_3 ) ;
} else {
F_32 ( & V_88 -> V_49 , V_3 ) ;
V_3 = V_88 -> V_49 . V_60 ;
F_32 ( & V_88 -> V_46 , V_3 ) ;
F_32 ( & V_88 -> V_111 , V_3 ) ;
F_37 ( V_88 -> V_51 , V_3 ) ;
F_37 ( V_88 -> V_53 , V_3 ) ;
}
break;
case V_52 :
V_84 = F_35 ( V_88 , V_59 -> V_76 ) ;
if ( V_59 -> type == V_70 ) {
F_31 ( & V_88 -> V_53 -> V_64 [ V_84 ] . V_107 , V_3 ) ;
} else {
F_32 ( & V_88 -> V_53 -> V_64 [ V_84 ] . V_107 , V_3 ) ;
V_3 = V_88 -> V_53 -> V_64 [ V_84 ] . V_107 . V_60 ;
F_32 ( & V_88 -> V_46 , V_3 ) ;
F_32 ( & V_88 -> V_49 , V_3 ) ;
F_32 ( & V_88 -> V_111 , V_3 ) ;
F_37 ( V_88 -> V_51 , V_3 ) ;
F_37 ( V_88 -> V_53 , V_3 ) ;
}
break;
case V_54 :
if ( V_59 -> type == V_70 ) {
F_31 ( & V_88 -> V_46 , V_3 ) ;
F_31 ( & V_88 -> V_49 , V_3 ) ;
F_31 ( & V_88 -> V_55 , V_3 ) ;
F_31 ( & V_88 -> V_111 , V_3 ) ;
F_38 ( V_88 -> V_51 , V_3 ) ;
F_38 ( V_88 -> V_53 , V_3 ) ;
} else {
F_32 ( & V_88 -> V_46 , V_3 ) ;
F_32 ( & V_88 -> V_49 , V_3 ) ;
F_32 ( & V_88 -> V_55 , V_3 ) ;
F_32 ( & V_88 -> V_111 , V_3 ) ;
F_37 ( V_88 -> V_51 , V_3 ) ;
F_37 ( V_88 -> V_53 , V_3 ) ;
}
}
}
static int F_41 ( struct V_20 * V_21 ,
struct V_24 * * V_25 , struct V_24 * * V_26 ,
unsigned int V_2 )
{
struct V_87 V_112 , V_113 ;
struct V_58 * V_59 ;
int V_114 ;
V_114 = F_22 ( & V_112 , V_21 -> V_36 ) ;
if ( V_114 )
return V_114 ;
V_114 = F_22 ( & V_113 , V_21 -> V_36 ) ;
if ( V_114 )
goto V_115;
V_114 = - V_100 ;
for ( V_59 = V_21 -> V_64 ; V_59 < V_21 -> V_64 + V_21 -> V_36 ; V_59 ++ ) {
if ( V_59 -> type != V_70 &&
V_59 -> type != V_65 )
goto V_116;
if ( V_59 -> V_66 & ~ V_117 )
goto V_116;
if ( ( V_59 -> V_66 & V_62 ) == 0 ) {
F_39 ( & V_112 , V_59 ) ;
continue;
}
if ( ! ( V_2 & V_11 ) )
goto V_116;
F_39 ( & V_113 , V_59 ) ;
if ( ! ( V_59 -> V_66 & V_63 ) )
F_39 ( & V_112 , V_59 ) ;
}
* V_25 = F_28 ( & V_112 , V_2 ) ;
if ( F_7 ( * V_25 ) ) {
V_114 = F_8 ( * V_25 ) ;
* V_25 = NULL ;
goto V_116;
}
* V_26 = F_28 ( & V_113 ,
V_2 | V_37 ) ;
if ( F_7 ( * V_26 ) ) {
V_114 = F_8 ( * V_26 ) ;
* V_26 = NULL ;
F_13 ( * V_25 ) ;
* V_25 = NULL ;
goto V_116;
}
F_21 ( * V_25 ) ;
F_21 ( * V_26 ) ;
V_114 = 0 ;
V_116:
F_25 ( & V_113 ) ;
V_115:
F_25 ( & V_112 ) ;
return V_114 ;
}
T_4
F_42 ( struct V_17 * V_18 , struct V_118 * V_119 ,
struct V_20 * V_21 )
{
T_4 error ;
int V_120 ;
struct V_19 * V_19 ;
struct V_22 * V_22 ;
struct V_24 * V_25 = NULL , * V_26 = NULL ;
unsigned int V_2 = 0 ;
error = F_43 ( V_18 , V_119 , 0 , V_121 ) ;
if ( error )
return error ;
V_19 = V_119 -> V_122 ;
V_22 = V_19 -> V_23 ;
if ( ! V_22 -> V_123 -> V_124 || ! F_44 ( V_22 ) )
return V_125 ;
if ( F_9 ( V_22 -> V_29 ) )
V_2 = V_11 ;
V_120 = F_41 ( V_21 , & V_25 , & V_26 , V_2 ) ;
if ( V_120 == - V_100 )
return V_125 ;
if ( V_120 < 0 )
goto V_126;
V_120 = V_22 -> V_123 -> V_124 ( V_22 , V_25 , V_28 ) ;
if ( V_120 < 0 )
goto V_127;
if ( F_9 ( V_22 -> V_29 ) ) {
V_120 = V_22 -> V_123 -> V_124 ( V_22 , V_26 ,
V_32 ) ;
}
V_127:
F_13 ( V_25 ) ;
F_13 ( V_26 ) ;
V_126:
if ( V_120 == - V_128 )
return V_125 ;
else
return F_45 ( V_120 ) ;
}
static short
F_40 ( struct V_58 * V_59 )
{
switch ( V_59 -> V_68 ) {
case V_71 :
return ( V_59 -> V_66 & V_75 ?
V_52 : V_50 ) ;
case V_69 :
return V_45 ;
case V_74 :
return V_48 ;
case V_78 :
return V_54 ;
}
F_46 () ;
return - 1 ;
}
int F_11 ( int V_129 )
{
return sizeof( struct V_20 ) + V_129 * sizeof( struct V_58 ) ;
}
int
F_47 ( char * V_130 , T_1 V_131 )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < F_48 ( V_132 ) ; V_84 ++ ) {
if ( V_132 [ V_84 ] . V_133 == V_131 &&
0 == memcmp ( V_132 [ V_84 ] . string , V_130 , V_131 ) )
return V_132 [ V_84 ] . type ;
}
return V_71 ;
}
T_4 F_49 ( struct V_134 * V_135 , int V_136 )
{
T_4 * V_130 ;
int V_84 ;
for ( V_84 = 0 ; V_84 < F_48 ( V_132 ) ; V_84 ++ ) {
if ( V_132 [ V_84 ] . type != V_136 )
continue;
V_130 = F_50 ( V_135 , V_132 [ V_84 ] . V_133 + 4 ) ;
if ( ! V_130 )
return V_137 ;
V_130 = F_51 ( V_130 , V_132 [ V_84 ] . string ,
V_132 [ V_84 ] . V_133 ) ;
return 0 ;
}
F_52 ( 1 ) ;
return V_138 ;
}
