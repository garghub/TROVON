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
struct V_22 * V_22 = F_5 ( V_19 ) ;
int error = 0 ;
struct V_23 * V_24 = NULL , * V_25 = NULL ;
unsigned int V_2 = 0 ;
int V_26 = 0 ;
V_24 = F_6 ( V_22 , V_27 ) ;
if ( ! V_24 )
V_24 = F_7 ( V_22 -> V_28 , V_29 ) ;
if ( F_8 ( V_24 ) )
return F_9 ( V_24 ) ;
V_26 += 2 * V_24 -> V_30 ;
if ( F_10 ( V_22 -> V_28 ) ) {
V_2 = V_11 ;
V_25 = F_6 ( V_22 , V_31 ) ;
if ( F_8 ( V_25 ) ) {
error = F_9 ( V_25 ) ;
goto V_32;
}
if ( V_25 )
V_26 += 2 * V_25 -> V_30 ;
}
* V_21 = F_11 ( F_12 ( V_26 ) , V_29 ) ;
if ( * V_21 == NULL ) {
error = - V_33 ;
goto V_34;
}
( * V_21 ) -> V_35 = 0 ;
F_13 ( V_24 , * V_21 , V_2 & ~ V_36 ) ;
if ( V_25 )
F_13 ( V_25 , * V_21 , V_2 | V_36 ) ;
V_34:
F_14 ( V_25 ) ;
V_32:
F_14 ( V_24 ) ;
return error ;
}
static void
F_15 ( struct V_23 * V_21 , struct V_37 * V_38 )
{
struct V_39 * V_40 , * V_41 ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_38 -> V_3 = 07 ;
V_41 = V_21 -> V_42 + V_21 -> V_30 ;
F_16 (pa, acl, pe) {
switch ( V_40 -> V_43 ) {
case V_44 :
V_38 -> V_45 = V_40 -> V_46 ;
break;
case V_47 :
V_38 -> V_48 = V_40 -> V_46 ;
break;
case V_49 :
V_38 -> V_50 |= V_40 -> V_46 ;
break;
case V_51 :
V_38 -> V_52 |= V_40 -> V_46 ;
break;
case V_53 :
V_38 -> V_54 = V_40 -> V_46 ;
break;
case V_55 :
V_38 -> V_3 = V_40 -> V_46 ;
break;
}
}
V_38 -> V_50 &= V_38 -> V_3 ;
V_38 -> V_48 &= V_38 -> V_3 ;
V_38 -> V_52 &= V_38 -> V_3 ;
}
static void
F_13 ( struct V_23 * V_24 , struct V_20 * V_21 ,
unsigned int V_2 )
{
struct V_39 * V_40 , * V_56 ;
struct V_57 * V_58 ;
struct V_37 V_38 ;
unsigned short V_59 ;
int V_60 = ( ( V_2 & V_36 ) ?
V_61 | V_62 : 0 ) ;
F_17 ( V_24 -> V_30 < 3 ) ;
F_15 ( V_24 , & V_38 ) ;
V_40 = V_24 -> V_42 ;
V_58 = V_21 -> V_63 + V_21 -> V_35 ;
V_59 = ~ V_38 . V_45 ;
V_59 &= V_38 . V_50 | V_38 . V_48 | V_38 . V_52 | V_38 . V_54 ;
if ( V_59 ) {
V_58 -> type = V_64 ;
V_58 -> V_65 = V_60 ;
V_58 -> V_66 = F_2 ( V_59 , V_2 ) ;
V_58 -> V_67 = V_68 ;
V_58 ++ ;
V_21 -> V_35 ++ ;
}
V_58 -> type = V_69 ;
V_58 -> V_65 = V_60 ;
V_58 -> V_66 = F_1 ( V_40 -> V_46 , V_2 | V_5 ) ;
V_58 -> V_67 = V_68 ;
V_58 ++ ;
V_21 -> V_35 ++ ;
V_40 ++ ;
while ( V_40 -> V_43 == V_49 ) {
V_59 = ~ ( V_40 -> V_46 & V_38 . V_3 ) ;
V_59 &= V_38 . V_52 | V_38 . V_48 | V_38 . V_54 ;
if ( V_59 ) {
V_58 -> type = V_64 ;
V_58 -> V_65 = V_60 ;
V_58 -> V_66 = F_2 ( V_59 , V_2 ) ;
V_58 -> V_67 = V_70 ;
V_58 -> V_71 = V_40 -> V_72 ;
V_58 ++ ;
V_21 -> V_35 ++ ;
}
V_58 -> type = V_69 ;
V_58 -> V_65 = V_60 ;
V_58 -> V_66 = F_1 ( V_40 -> V_46 & V_38 . V_3 ,
V_2 ) ;
V_58 -> V_67 = V_70 ;
V_58 -> V_71 = V_40 -> V_72 ;
V_58 ++ ;
V_21 -> V_35 ++ ;
V_40 ++ ;
}
V_56 = V_40 ;
V_58 -> type = V_69 ;
V_58 -> V_65 = V_60 ;
V_58 -> V_66 = F_1 ( V_38 . V_48 , V_2 ) ;
V_58 -> V_67 = V_73 ;
V_58 ++ ;
V_21 -> V_35 ++ ;
V_40 ++ ;
while ( V_40 -> V_43 == V_51 ) {
V_58 -> type = V_69 ;
V_58 -> V_65 = V_60 | V_74 ;
V_58 -> V_66 = F_1 ( V_40 -> V_46 & V_38 . V_3 ,
V_2 ) ;
V_58 -> V_67 = V_70 ;
V_58 -> V_75 = V_40 -> V_76 ;
V_58 ++ ;
V_21 -> V_35 ++ ;
V_40 ++ ;
}
V_40 = V_56 ;
V_59 = ~ V_38 . V_48 & V_38 . V_54 ;
if ( V_59 ) {
V_58 -> type = V_64 ;
V_58 -> V_65 = V_60 ;
V_58 -> V_66 = F_2 ( V_59 , V_2 ) ;
V_58 -> V_67 = V_73 ;
V_58 ++ ;
V_21 -> V_35 ++ ;
}
V_40 ++ ;
while ( V_40 -> V_43 == V_51 ) {
V_59 = ~ ( V_40 -> V_46 & V_38 . V_3 ) ;
V_59 &= V_38 . V_54 ;
if ( V_59 ) {
V_58 -> type = V_64 ;
V_58 -> V_65 = V_60 | V_74 ;
V_58 -> V_66 = F_2 ( V_59 , V_2 ) ;
V_58 -> V_67 = V_70 ;
V_58 -> V_75 = V_40 -> V_76 ;
V_58 ++ ;
V_21 -> V_35 ++ ;
}
V_40 ++ ;
}
if ( V_40 -> V_43 == V_55 )
V_40 ++ ;
V_58 -> type = V_69 ;
V_58 -> V_65 = V_60 ;
V_58 -> V_66 = F_1 ( V_40 -> V_46 , V_2 ) ;
V_58 -> V_67 = V_77 ;
V_21 -> V_35 ++ ;
}
static bool
F_18 ( struct V_39 * V_78 , struct V_39 * V_79 )
{
if ( V_78 -> V_43 != V_79 -> V_43 )
return V_78 -> V_43 > V_79 -> V_43 ;
if ( V_78 -> V_43 == V_49 )
return F_19 ( V_78 -> V_72 , V_79 -> V_72 ) ;
if ( V_78 -> V_43 == V_51 )
return F_20 ( V_78 -> V_76 , V_79 -> V_76 ) ;
return false ;
}
static void
F_21 ( struct V_23 * V_24 , int V_80 , int V_81 ) {
int V_82 = 0 , V_83 ;
struct V_39 V_84 ;
while ( ! V_82 ) {
V_82 = 1 ;
for ( V_83 = V_80 ; V_83 < V_81 ; V_83 ++ ) {
if ( F_18 ( & V_24 -> V_42 [ V_83 ] ,
& V_24 -> V_42 [ V_83 + 1 ] ) ) {
V_82 = 0 ;
V_84 = V_24 -> V_42 [ V_83 ] ;
V_24 -> V_42 [ V_83 ] = V_24 -> V_42 [ V_83 + 1 ] ;
V_24 -> V_42 [ V_83 + 1 ] = V_84 ;
}
}
}
}
static void
F_22 ( struct V_23 * V_24 )
{
int V_83 , V_85 ;
if ( ! V_24 || V_24 -> V_30 <= 4 )
return;
V_83 = 1 ;
while ( V_24 -> V_42 [ V_83 ] . V_43 == V_49 )
V_83 ++ ;
F_21 ( V_24 , 1 , V_83 - 1 ) ;
F_17 ( V_24 -> V_42 [ V_83 ] . V_43 != V_47 ) ;
V_85 = ++ V_83 ;
while ( V_24 -> V_42 [ V_85 ] . V_43 == V_51 )
V_85 ++ ;
F_21 ( V_24 , V_83 , V_85 - 1 ) ;
return;
}
static int
F_23 ( struct V_86 * V_87 , int V_88 )
{
int V_89 ;
memset ( V_87 , 0 , sizeof( struct V_86 ) ) ;
V_87 -> V_90 = 1 ;
V_89 = sizeof( struct V_91 )
+ V_88 * sizeof( struct V_92 ) ;
V_87 -> V_50 = F_24 ( V_89 , V_29 ) ;
if ( ! V_87 -> V_50 )
return - V_33 ;
V_87 -> V_52 = F_24 ( V_89 , V_29 ) ;
if ( ! V_87 -> V_52 ) {
F_25 ( V_87 -> V_50 ) ;
return - V_33 ;
}
return 0 ;
}
static void
F_26 ( struct V_86 * V_87 ) {
F_25 ( V_87 -> V_50 ) ;
F_25 ( V_87 -> V_52 ) ;
}
static inline void F_27 ( struct V_86 * V_87 , struct V_93 * V_94 )
{
V_87 -> V_3 . V_95 |= V_94 -> V_95 ;
}
static struct V_23 *
F_28 ( struct V_86 * V_87 , unsigned int V_2 )
{
struct V_39 * V_96 ;
struct V_23 * V_24 ;
int V_97 ;
int V_83 ;
if ( V_87 -> V_90 && ( V_2 & V_36 ) )
return NULL ;
if ( ! V_87 -> V_50 -> V_98 && ! V_87 -> V_52 -> V_98 )
V_97 = 3 ;
else
V_97 = 4 + V_87 -> V_50 -> V_98 + V_87 -> V_52 -> V_98 ;
V_24 = F_29 ( V_97 , V_29 ) ;
if ( ! V_24 )
return F_30 ( - V_33 ) ;
V_96 = V_24 -> V_42 ;
V_96 -> V_43 = V_44 ;
F_3 ( V_87 -> V_45 . V_95 , & V_96 -> V_46 , V_2 ) ;
for ( V_83 = 0 ; V_83 < V_87 -> V_50 -> V_98 ; V_83 ++ ) {
V_96 ++ ;
V_96 -> V_43 = V_49 ;
F_3 ( V_87 -> V_50 -> V_63 [ V_83 ] . V_99 . V_95 ,
& V_96 -> V_46 , V_2 ) ;
V_96 -> V_72 = V_87 -> V_50 -> V_63 [ V_83 ] . V_100 ;
F_27 ( V_87 , & V_87 -> V_50 -> V_63 [ V_83 ] . V_99 ) ;
}
V_96 ++ ;
V_96 -> V_43 = V_47 ;
F_3 ( V_87 -> V_48 . V_95 , & V_96 -> V_46 , V_2 ) ;
F_27 ( V_87 , & V_87 -> V_48 ) ;
for ( V_83 = 0 ; V_83 < V_87 -> V_52 -> V_98 ; V_83 ++ ) {
V_96 ++ ;
V_96 -> V_43 = V_51 ;
F_3 ( V_87 -> V_52 -> V_63 [ V_83 ] . V_99 . V_95 ,
& V_96 -> V_46 , V_2 ) ;
V_96 -> V_76 = V_87 -> V_52 -> V_63 [ V_83 ] . V_101 ;
F_27 ( V_87 , & V_87 -> V_52 -> V_63 [ V_83 ] . V_99 ) ;
}
if ( V_87 -> V_50 -> V_98 || V_87 -> V_52 -> V_98 ) {
V_96 ++ ;
V_96 -> V_43 = V_55 ;
F_3 ( V_87 -> V_3 . V_95 , & V_96 -> V_46 , V_2 ) ;
}
V_96 ++ ;
V_96 -> V_43 = V_53 ;
F_3 ( V_87 -> V_54 . V_95 , & V_96 -> V_46 , V_2 ) ;
return V_24 ;
}
static inline void F_31 ( struct V_93 * V_94 , T_1 V_3 )
{
V_94 -> V_95 |= V_3 & ~ V_94 -> V_59 ;
}
static inline void F_32 ( struct V_93 * V_94 , T_1 V_3 )
{
V_94 -> V_59 |= V_3 & ~ V_94 -> V_95 ;
}
static int F_33 ( struct V_86 * V_87 , T_2 V_100 )
{
struct V_91 * V_102 = V_87 -> V_50 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_102 -> V_98 ; V_83 ++ )
if ( F_34 ( V_102 -> V_63 [ V_83 ] . V_100 , V_100 ) )
return V_83 ;
V_102 -> V_98 ++ ;
V_102 -> V_63 [ V_83 ] . V_100 = V_100 ;
V_102 -> V_63 [ V_83 ] . V_99 . V_95 = V_87 -> V_103 . V_95 ;
V_102 -> V_63 [ V_83 ] . V_99 . V_59 = V_87 -> V_103 . V_59 ;
return V_83 ;
}
static int F_35 ( struct V_86 * V_87 , T_3 V_101 )
{
struct V_91 * V_102 = V_87 -> V_52 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_102 -> V_98 ; V_83 ++ )
if ( F_36 ( V_102 -> V_63 [ V_83 ] . V_101 , V_101 ) )
return V_83 ;
V_102 -> V_98 ++ ;
V_102 -> V_63 [ V_83 ] . V_101 = V_101 ;
V_102 -> V_63 [ V_83 ] . V_99 . V_95 = V_87 -> V_103 . V_95 ;
V_102 -> V_63 [ V_83 ] . V_99 . V_59 = V_87 -> V_103 . V_59 ;
return V_83 ;
}
static void F_37 ( struct V_91 * V_102 , T_1 V_3 )
{
int V_83 ;
for ( V_83 = 0 ; V_83 < V_102 -> V_98 ; V_83 ++ )
F_32 ( & V_102 -> V_63 [ V_83 ] . V_99 , V_3 ) ;
}
static void F_38 ( struct V_91 * V_102 , T_1 V_3 )
{
int V_83 ;
for ( V_83 = 0 ; V_83 < V_102 -> V_98 ; V_83 ++ )
F_31 ( & V_102 -> V_63 [ V_83 ] . V_99 , V_3 ) ;
}
static void F_39 ( struct V_86 * V_87 ,
struct V_57 * V_58 )
{
T_1 V_3 = V_58 -> V_66 ;
int V_83 ;
V_87 -> V_90 = 0 ;
switch ( F_40 ( V_58 ) ) {
case V_44 :
if ( V_58 -> type == V_69 ) {
F_31 ( & V_87 -> V_45 , V_3 ) ;
} else {
F_32 ( & V_87 -> V_45 , V_3 ) ;
}
break;
case V_49 :
V_83 = F_33 ( V_87 , V_58 -> V_71 ) ;
if ( V_58 -> type == V_69 ) {
F_31 ( & V_87 -> V_50 -> V_63 [ V_83 ] . V_99 , V_3 ) ;
} else {
F_32 ( & V_87 -> V_50 -> V_63 [ V_83 ] . V_99 , V_3 ) ;
V_3 = V_87 -> V_50 -> V_63 [ V_83 ] . V_99 . V_59 ;
F_32 ( & V_87 -> V_45 , V_3 ) ;
}
break;
case V_47 :
if ( V_58 -> type == V_69 ) {
F_31 ( & V_87 -> V_48 , V_3 ) ;
} else {
F_32 ( & V_87 -> V_48 , V_3 ) ;
V_3 = V_87 -> V_48 . V_59 ;
F_32 ( & V_87 -> V_45 , V_3 ) ;
F_32 ( & V_87 -> V_103 , V_3 ) ;
F_37 ( V_87 -> V_50 , V_3 ) ;
F_37 ( V_87 -> V_52 , V_3 ) ;
}
break;
case V_51 :
V_83 = F_35 ( V_87 , V_58 -> V_75 ) ;
if ( V_58 -> type == V_69 ) {
F_31 ( & V_87 -> V_52 -> V_63 [ V_83 ] . V_99 , V_3 ) ;
} else {
F_32 ( & V_87 -> V_52 -> V_63 [ V_83 ] . V_99 , V_3 ) ;
V_3 = V_87 -> V_52 -> V_63 [ V_83 ] . V_99 . V_59 ;
F_32 ( & V_87 -> V_45 , V_3 ) ;
F_32 ( & V_87 -> V_48 , V_3 ) ;
F_32 ( & V_87 -> V_103 , V_3 ) ;
F_37 ( V_87 -> V_50 , V_3 ) ;
F_37 ( V_87 -> V_52 , V_3 ) ;
}
break;
case V_53 :
if ( V_58 -> type == V_69 ) {
F_31 ( & V_87 -> V_45 , V_3 ) ;
F_31 ( & V_87 -> V_48 , V_3 ) ;
F_31 ( & V_87 -> V_54 , V_3 ) ;
F_31 ( & V_87 -> V_103 , V_3 ) ;
F_38 ( V_87 -> V_50 , V_3 ) ;
F_38 ( V_87 -> V_52 , V_3 ) ;
} else {
F_32 ( & V_87 -> V_45 , V_3 ) ;
F_32 ( & V_87 -> V_48 , V_3 ) ;
F_32 ( & V_87 -> V_54 , V_3 ) ;
F_32 ( & V_87 -> V_103 , V_3 ) ;
F_37 ( V_87 -> V_50 , V_3 ) ;
F_37 ( V_87 -> V_52 , V_3 ) ;
}
}
}
static int F_41 ( struct V_20 * V_21 ,
struct V_23 * * V_24 , struct V_23 * * V_25 ,
unsigned int V_2 )
{
struct V_86 V_104 , V_105 ;
struct V_57 * V_58 ;
int V_106 ;
V_106 = F_23 ( & V_104 , V_21 -> V_35 ) ;
if ( V_106 )
return V_106 ;
V_106 = F_23 ( & V_105 , V_21 -> V_35 ) ;
if ( V_106 )
goto V_107;
V_106 = - V_108 ;
for ( V_58 = V_21 -> V_63 ; V_58 < V_21 -> V_63 + V_21 -> V_35 ; V_58 ++ ) {
if ( V_58 -> type != V_69 &&
V_58 -> type != V_64 )
goto V_109;
if ( V_58 -> V_65 & ~ V_110 )
goto V_109;
if ( ( V_58 -> V_65 & V_61 ) == 0 ) {
F_39 ( & V_104 , V_58 ) ;
continue;
}
if ( ! ( V_2 & V_11 ) )
goto V_109;
F_39 ( & V_105 , V_58 ) ;
if ( ! ( V_58 -> V_65 & V_62 ) )
F_39 ( & V_104 , V_58 ) ;
}
* V_24 = F_28 ( & V_104 , V_2 ) ;
if ( F_8 ( * V_24 ) ) {
V_106 = F_9 ( * V_24 ) ;
* V_24 = NULL ;
goto V_109;
}
* V_25 = F_28 ( & V_105 ,
V_2 | V_36 ) ;
if ( F_8 ( * V_25 ) ) {
V_106 = F_9 ( * V_25 ) ;
* V_25 = NULL ;
F_14 ( * V_24 ) ;
* V_24 = NULL ;
goto V_109;
}
F_22 ( * V_24 ) ;
F_22 ( * V_25 ) ;
V_106 = 0 ;
V_109:
F_26 ( & V_105 ) ;
V_107:
F_26 ( & V_104 ) ;
return V_106 ;
}
T_4
F_42 ( struct V_17 * V_18 , struct V_111 * V_112 ,
struct V_20 * V_21 )
{
T_4 error ;
int V_113 ;
struct V_19 * V_19 ;
struct V_22 * V_22 ;
struct V_23 * V_24 = NULL , * V_25 = NULL ;
unsigned int V_2 = 0 ;
error = F_43 ( V_18 , V_112 , 0 , V_114 ) ;
if ( error )
return error ;
V_19 = V_112 -> V_115 ;
V_22 = F_5 ( V_19 ) ;
if ( ! V_22 -> V_116 -> V_117 || ! F_44 ( V_22 ) )
return V_118 ;
if ( F_10 ( V_22 -> V_28 ) )
V_2 = V_11 ;
V_113 = F_41 ( V_21 , & V_24 , & V_25 , V_2 ) ;
if ( V_113 == - V_108 )
return V_118 ;
if ( V_113 < 0 )
goto V_119;
V_113 = V_22 -> V_116 -> V_117 ( V_22 , V_24 , V_27 ) ;
if ( V_113 < 0 )
goto V_120;
if ( F_10 ( V_22 -> V_28 ) ) {
V_113 = V_22 -> V_116 -> V_117 ( V_22 , V_25 ,
V_31 ) ;
}
V_120:
F_14 ( V_24 ) ;
F_14 ( V_25 ) ;
V_119:
if ( V_113 == - V_121 )
return V_118 ;
else
return F_45 ( V_113 ) ;
}
static short
F_40 ( struct V_57 * V_58 )
{
switch ( V_58 -> V_67 ) {
case V_70 :
return ( V_58 -> V_65 & V_74 ?
V_51 : V_49 ) ;
case V_68 :
return V_44 ;
case V_73 :
return V_47 ;
case V_77 :
return V_53 ;
}
F_46 () ;
return - 1 ;
}
int F_12 ( int V_122 )
{
return sizeof( struct V_20 ) + V_122 * sizeof( struct V_57 ) ;
}
int
F_47 ( char * V_123 , T_1 V_124 )
{
int V_83 ;
for ( V_83 = 0 ; V_83 < F_48 ( V_125 ) ; V_83 ++ ) {
if ( V_125 [ V_83 ] . V_126 == V_124 &&
0 == memcmp ( V_125 [ V_83 ] . string , V_123 , V_124 ) )
return V_125 [ V_83 ] . type ;
}
return V_70 ;
}
T_4 F_49 ( struct V_127 * V_128 , int V_129 )
{
T_4 * V_123 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < F_48 ( V_125 ) ; V_83 ++ ) {
if ( V_125 [ V_83 ] . type != V_129 )
continue;
V_123 = F_50 ( V_128 , V_125 [ V_83 ] . V_126 + 4 ) ;
if ( ! V_123 )
return V_130 ;
V_123 = F_51 ( V_123 , V_125 [ V_83 ] . string ,
V_125 [ V_83 ] . V_126 ) ;
return 0 ;
}
F_52 ( 1 ) ;
return V_131 ;
}
