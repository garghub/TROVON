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
if ( ! V_25 ) {
V_25 = F_6 ( V_22 -> V_29 , V_30 ) ;
if ( F_7 ( V_25 ) )
return F_8 ( V_25 ) ;
}
V_27 += 2 * V_25 -> V_31 ;
if ( F_9 ( V_22 -> V_29 ) ) {
V_2 = V_11 ;
V_26 = F_5 ( V_22 , V_32 ) ;
if ( V_26 )
V_27 += 2 * V_26 -> V_31 ;
}
* V_21 = F_10 ( V_27 ) ;
if ( * V_21 == NULL ) {
error = - V_33 ;
goto V_34;
}
F_11 ( V_25 , * V_21 , V_2 & ~ V_35 ) ;
if ( V_26 )
F_11 ( V_26 , * V_21 , V_2 | V_35 ) ;
V_34:
F_12 ( V_25 ) ;
F_12 ( V_26 ) ;
return error ;
}
static void
F_13 ( struct V_24 * V_21 , struct V_36 * V_37 )
{
struct V_38 * V_39 , * V_40 ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_3 = 07 ;
V_40 = V_21 -> V_41 + V_21 -> V_31 ;
F_14 (pa, acl, pe) {
switch ( V_39 -> V_42 ) {
case V_43 :
V_37 -> V_44 = V_39 -> V_45 ;
break;
case V_46 :
V_37 -> V_47 = V_39 -> V_45 ;
break;
case V_48 :
V_37 -> V_49 |= V_39 -> V_45 ;
break;
case V_50 :
V_37 -> V_51 |= V_39 -> V_45 ;
break;
case V_52 :
V_37 -> V_53 = V_39 -> V_45 ;
break;
case V_54 :
V_37 -> V_3 = V_39 -> V_45 ;
break;
}
}
V_37 -> V_49 &= V_37 -> V_3 ;
V_37 -> V_47 &= V_37 -> V_3 ;
V_37 -> V_51 &= V_37 -> V_3 ;
}
static void
F_11 ( struct V_24 * V_25 , struct V_20 * V_21 ,
unsigned int V_2 )
{
struct V_38 * V_39 , * V_55 ;
struct V_56 * V_57 ;
struct V_36 V_37 ;
unsigned short V_58 ;
int V_59 = ( ( V_2 & V_35 ) ?
V_60 | V_61 : 0 ) ;
F_15 ( V_25 -> V_31 < 3 ) ;
F_13 ( V_25 , & V_37 ) ;
V_39 = V_25 -> V_41 ;
V_57 = V_21 -> V_62 + V_21 -> V_63 ;
V_58 = ~ V_37 . V_44 ;
V_58 &= V_37 . V_49 | V_37 . V_47 | V_37 . V_51 | V_37 . V_53 ;
if ( V_58 ) {
V_57 -> type = V_64 ;
V_57 -> V_65 = V_59 ;
V_57 -> V_66 = F_2 ( V_58 , V_2 ) ;
V_57 -> V_67 = V_68 ;
V_57 ++ ;
V_21 -> V_63 ++ ;
}
V_57 -> type = V_69 ;
V_57 -> V_65 = V_59 ;
V_57 -> V_66 = F_1 ( V_39 -> V_45 , V_2 | V_5 ) ;
V_57 -> V_67 = V_68 ;
V_57 ++ ;
V_21 -> V_63 ++ ;
V_39 ++ ;
while ( V_39 -> V_42 == V_48 ) {
V_58 = ~ ( V_39 -> V_45 & V_37 . V_3 ) ;
V_58 &= V_37 . V_51 | V_37 . V_47 | V_37 . V_53 ;
if ( V_58 ) {
V_57 -> type = V_64 ;
V_57 -> V_65 = V_59 ;
V_57 -> V_66 = F_2 ( V_58 , V_2 ) ;
V_57 -> V_67 = V_70 ;
V_57 -> V_71 = V_39 -> V_72 ;
V_57 ++ ;
V_21 -> V_63 ++ ;
}
V_57 -> type = V_69 ;
V_57 -> V_65 = V_59 ;
V_57 -> V_66 = F_1 ( V_39 -> V_45 & V_37 . V_3 ,
V_2 ) ;
V_57 -> V_67 = V_70 ;
V_57 -> V_71 = V_39 -> V_72 ;
V_57 ++ ;
V_21 -> V_63 ++ ;
V_39 ++ ;
}
V_55 = V_39 ;
V_57 -> type = V_69 ;
V_57 -> V_65 = V_59 ;
V_57 -> V_66 = F_1 ( V_37 . V_47 , V_2 ) ;
V_57 -> V_67 = V_73 ;
V_57 ++ ;
V_21 -> V_63 ++ ;
V_39 ++ ;
while ( V_39 -> V_42 == V_50 ) {
V_57 -> type = V_69 ;
V_57 -> V_65 = V_59 | V_74 ;
V_57 -> V_66 = F_1 ( V_39 -> V_45 & V_37 . V_3 ,
V_2 ) ;
V_57 -> V_67 = V_70 ;
V_57 -> V_75 = V_39 -> V_76 ;
V_57 ++ ;
V_21 -> V_63 ++ ;
V_39 ++ ;
}
V_39 = V_55 ;
V_58 = ~ V_37 . V_47 & V_37 . V_53 ;
if ( V_58 ) {
V_57 -> type = V_64 ;
V_57 -> V_65 = V_59 ;
V_57 -> V_66 = F_2 ( V_58 , V_2 ) ;
V_57 -> V_67 = V_73 ;
V_57 ++ ;
V_21 -> V_63 ++ ;
}
V_39 ++ ;
while ( V_39 -> V_42 == V_50 ) {
V_58 = ~ ( V_39 -> V_45 & V_37 . V_3 ) ;
V_58 &= V_37 . V_53 ;
if ( V_58 ) {
V_57 -> type = V_64 ;
V_57 -> V_65 = V_59 | V_74 ;
V_57 -> V_66 = F_2 ( V_58 , V_2 ) ;
V_57 -> V_67 = V_70 ;
V_57 -> V_75 = V_39 -> V_76 ;
V_57 ++ ;
V_21 -> V_63 ++ ;
}
V_39 ++ ;
}
if ( V_39 -> V_42 == V_54 )
V_39 ++ ;
V_57 -> type = V_69 ;
V_57 -> V_65 = V_59 ;
V_57 -> V_66 = F_1 ( V_39 -> V_45 , V_2 ) ;
V_57 -> V_67 = V_77 ;
V_21 -> V_63 ++ ;
}
static bool
F_16 ( struct V_38 * V_78 , struct V_38 * V_79 )
{
if ( V_78 -> V_42 != V_79 -> V_42 )
return V_78 -> V_42 > V_79 -> V_42 ;
if ( V_78 -> V_42 == V_48 )
return F_17 ( V_78 -> V_72 , V_79 -> V_72 ) ;
if ( V_78 -> V_42 == V_50 )
return F_18 ( V_78 -> V_76 , V_79 -> V_76 ) ;
return false ;
}
static void
F_19 ( struct V_24 * V_25 , int V_80 , int V_81 ) {
int V_82 = 0 , V_83 ;
struct V_38 V_84 ;
while ( ! V_82 ) {
V_82 = 1 ;
for ( V_83 = V_80 ; V_83 < V_81 ; V_83 ++ ) {
if ( F_16 ( & V_25 -> V_41 [ V_83 ] ,
& V_25 -> V_41 [ V_83 + 1 ] ) ) {
V_82 = 0 ;
V_84 = V_25 -> V_41 [ V_83 ] ;
V_25 -> V_41 [ V_83 ] = V_25 -> V_41 [ V_83 + 1 ] ;
V_25 -> V_41 [ V_83 + 1 ] = V_84 ;
}
}
}
}
static void
F_20 ( struct V_24 * V_25 )
{
int V_83 , V_85 ;
if ( V_25 -> V_31 <= 4 )
return;
V_83 = 1 ;
while ( V_25 -> V_41 [ V_83 ] . V_42 == V_48 )
V_83 ++ ;
F_19 ( V_25 , 1 , V_83 - 1 ) ;
F_15 ( V_25 -> V_41 [ V_83 ] . V_42 != V_46 ) ;
V_85 = ++ V_83 ;
while ( V_25 -> V_41 [ V_85 ] . V_42 == V_50 )
V_85 ++ ;
F_19 ( V_25 , V_83 , V_85 - 1 ) ;
return;
}
static int
F_21 ( struct V_86 * V_87 , int V_88 )
{
int V_89 ;
memset ( V_87 , 0 , sizeof( struct V_86 ) ) ;
V_87 -> V_90 = 1 ;
V_89 = sizeof( struct V_91 )
+ V_88 * sizeof( struct V_92 ) ;
V_87 -> V_49 = F_22 ( V_89 , V_30 ) ;
if ( ! V_87 -> V_49 )
return - V_33 ;
V_87 -> V_51 = F_22 ( V_89 , V_30 ) ;
if ( ! V_87 -> V_51 ) {
F_23 ( V_87 -> V_49 ) ;
return - V_33 ;
}
return 0 ;
}
static void
F_24 ( struct V_86 * V_87 ) {
F_23 ( V_87 -> V_49 ) ;
F_23 ( V_87 -> V_51 ) ;
}
static inline void F_25 ( struct V_86 * V_87 , struct V_93 * V_94 )
{
V_87 -> V_3 . V_95 |= V_94 -> V_95 ;
}
static inline int F_26 ( T_1 V_3 , int V_96 )
{
if ( V_3 & ( V_97 | V_98 ) )
return - V_99 ;
if ( ! V_96 )
return 0 ;
if ( V_3 & ( V_100 | V_101 ) )
return - V_99 ;
return 0 ;
}
static struct V_24 *
F_27 ( struct V_86 * V_87 , unsigned int V_2 )
{
struct V_38 * V_102 ;
struct V_24 * V_25 ;
int V_103 ;
int V_83 , error = 0 ;
if ( V_87 -> V_90 && ( V_2 & V_35 ) ) {
V_25 = F_28 ( 0 , V_30 ) ;
return V_25 ? V_25 : F_29 ( - V_33 ) ;
}
V_103 = 4 + V_87 -> V_49 -> V_104 + V_87 -> V_51 -> V_104 ;
V_25 = F_28 ( V_103 , V_30 ) ;
if ( ! V_25 )
return F_29 ( - V_33 ) ;
V_102 = V_25 -> V_41 ;
V_102 -> V_42 = V_43 ;
error = F_26 ( V_87 -> V_44 . V_58 , 1 ) ;
if ( error )
goto V_105;
F_3 ( V_87 -> V_44 . V_95 , & V_102 -> V_45 , V_2 ) ;
for ( V_83 = 0 ; V_83 < V_87 -> V_49 -> V_104 ; V_83 ++ ) {
V_102 ++ ;
V_102 -> V_42 = V_48 ;
error = F_26 ( V_87 -> V_49 -> V_62 [ V_83 ] . V_106 . V_58 , 0 ) ;
if ( error )
goto V_105;
F_3 ( V_87 -> V_49 -> V_62 [ V_83 ] . V_106 . V_95 ,
& V_102 -> V_45 , V_2 ) ;
V_102 -> V_72 = V_87 -> V_49 -> V_62 [ V_83 ] . V_107 ;
F_25 ( V_87 , & V_87 -> V_49 -> V_62 [ V_83 ] . V_106 ) ;
}
V_102 ++ ;
V_102 -> V_42 = V_46 ;
error = F_26 ( V_87 -> V_47 . V_58 , 0 ) ;
if ( error )
goto V_105;
F_3 ( V_87 -> V_47 . V_95 , & V_102 -> V_45 , V_2 ) ;
F_25 ( V_87 , & V_87 -> V_47 ) ;
for ( V_83 = 0 ; V_83 < V_87 -> V_51 -> V_104 ; V_83 ++ ) {
V_102 ++ ;
V_102 -> V_42 = V_50 ;
error = F_26 ( V_87 -> V_51 -> V_62 [ V_83 ] . V_106 . V_58 , 0 ) ;
if ( error )
goto V_105;
F_3 ( V_87 -> V_51 -> V_62 [ V_83 ] . V_106 . V_95 ,
& V_102 -> V_45 , V_2 ) ;
V_102 -> V_76 = V_87 -> V_51 -> V_62 [ V_83 ] . V_108 ;
F_25 ( V_87 , & V_87 -> V_51 -> V_62 [ V_83 ] . V_106 ) ;
}
V_102 ++ ;
V_102 -> V_42 = V_54 ;
F_3 ( V_87 -> V_3 . V_95 , & V_102 -> V_45 , V_2 ) ;
V_102 ++ ;
V_102 -> V_42 = V_52 ;
error = F_26 ( V_87 -> V_53 . V_58 , 0 ) ;
if ( error )
goto V_105;
F_3 ( V_87 -> V_53 . V_95 , & V_102 -> V_45 , V_2 ) ;
return V_25 ;
V_105:
F_12 ( V_25 ) ;
return F_29 ( error ) ;
}
static inline void F_30 ( struct V_93 * V_94 , T_1 V_3 )
{
V_94 -> V_95 |= V_3 & ~ V_94 -> V_58 ;
}
static inline void F_31 ( struct V_93 * V_94 , T_1 V_3 )
{
V_94 -> V_58 |= V_3 & ~ V_94 -> V_95 ;
}
static int F_32 ( struct V_86 * V_87 , T_2 V_107 )
{
struct V_91 * V_109 = V_87 -> V_49 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_109 -> V_104 ; V_83 ++ )
if ( F_33 ( V_109 -> V_62 [ V_83 ] . V_107 , V_107 ) )
return V_83 ;
V_109 -> V_104 ++ ;
V_109 -> V_62 [ V_83 ] . V_107 = V_107 ;
V_109 -> V_62 [ V_83 ] . V_106 . V_95 = V_87 -> V_110 . V_95 ;
V_109 -> V_62 [ V_83 ] . V_106 . V_58 = V_87 -> V_110 . V_58 ;
return V_83 ;
}
static int F_34 ( struct V_86 * V_87 , T_3 V_108 )
{
struct V_91 * V_109 = V_87 -> V_51 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_109 -> V_104 ; V_83 ++ )
if ( F_35 ( V_109 -> V_62 [ V_83 ] . V_108 , V_108 ) )
return V_83 ;
V_109 -> V_104 ++ ;
V_109 -> V_62 [ V_83 ] . V_108 = V_108 ;
V_109 -> V_62 [ V_83 ] . V_106 . V_95 = V_87 -> V_110 . V_95 ;
V_109 -> V_62 [ V_83 ] . V_106 . V_58 = V_87 -> V_110 . V_58 ;
return V_83 ;
}
static void F_36 ( struct V_91 * V_109 , T_1 V_3 )
{
int V_83 ;
for ( V_83 = 0 ; V_83 < V_109 -> V_104 ; V_83 ++ )
F_31 ( & V_109 -> V_62 [ V_83 ] . V_106 , V_3 ) ;
}
static void F_37 ( struct V_91 * V_109 , T_1 V_3 )
{
int V_83 ;
for ( V_83 = 0 ; V_83 < V_109 -> V_104 ; V_83 ++ )
F_30 ( & V_109 -> V_62 [ V_83 ] . V_106 , V_3 ) ;
}
static void F_38 ( struct V_86 * V_87 ,
struct V_56 * V_57 )
{
T_1 V_3 = V_57 -> V_66 ;
int V_83 ;
V_87 -> V_90 = 0 ;
switch ( F_39 ( V_57 ) ) {
case V_43 :
if ( V_57 -> type == V_69 ) {
F_30 ( & V_87 -> V_44 , V_3 ) ;
} else {
F_31 ( & V_87 -> V_44 , V_3 ) ;
}
break;
case V_48 :
V_83 = F_32 ( V_87 , V_57 -> V_71 ) ;
if ( V_57 -> type == V_69 ) {
F_30 ( & V_87 -> V_49 -> V_62 [ V_83 ] . V_106 , V_3 ) ;
} else {
F_31 ( & V_87 -> V_49 -> V_62 [ V_83 ] . V_106 , V_3 ) ;
V_3 = V_87 -> V_49 -> V_62 [ V_83 ] . V_106 . V_58 ;
F_31 ( & V_87 -> V_44 , V_3 ) ;
}
break;
case V_46 :
if ( V_57 -> type == V_69 ) {
F_30 ( & V_87 -> V_47 , V_3 ) ;
} else {
F_31 ( & V_87 -> V_47 , V_3 ) ;
V_3 = V_87 -> V_47 . V_58 ;
F_31 ( & V_87 -> V_44 , V_3 ) ;
F_31 ( & V_87 -> V_110 , V_3 ) ;
F_36 ( V_87 -> V_49 , V_3 ) ;
F_36 ( V_87 -> V_51 , V_3 ) ;
}
break;
case V_50 :
V_83 = F_34 ( V_87 , V_57 -> V_75 ) ;
if ( V_57 -> type == V_69 ) {
F_30 ( & V_87 -> V_51 -> V_62 [ V_83 ] . V_106 , V_3 ) ;
} else {
F_31 ( & V_87 -> V_51 -> V_62 [ V_83 ] . V_106 , V_3 ) ;
V_3 = V_87 -> V_51 -> V_62 [ V_83 ] . V_106 . V_58 ;
F_31 ( & V_87 -> V_44 , V_3 ) ;
F_31 ( & V_87 -> V_47 , V_3 ) ;
F_31 ( & V_87 -> V_110 , V_3 ) ;
F_36 ( V_87 -> V_49 , V_3 ) ;
F_36 ( V_87 -> V_51 , V_3 ) ;
}
break;
case V_52 :
if ( V_57 -> type == V_69 ) {
F_30 ( & V_87 -> V_44 , V_3 ) ;
F_30 ( & V_87 -> V_47 , V_3 ) ;
F_30 ( & V_87 -> V_53 , V_3 ) ;
F_30 ( & V_87 -> V_110 , V_3 ) ;
F_37 ( V_87 -> V_49 , V_3 ) ;
F_37 ( V_87 -> V_51 , V_3 ) ;
} else {
F_31 ( & V_87 -> V_44 , V_3 ) ;
F_31 ( & V_87 -> V_47 , V_3 ) ;
F_31 ( & V_87 -> V_53 , V_3 ) ;
F_31 ( & V_87 -> V_110 , V_3 ) ;
F_36 ( V_87 -> V_49 , V_3 ) ;
F_36 ( V_87 -> V_51 , V_3 ) ;
}
}
}
static int F_40 ( struct V_20 * V_21 ,
struct V_24 * * V_25 , struct V_24 * * V_26 ,
unsigned int V_2 )
{
struct V_86 V_111 , V_112 ;
struct V_56 * V_57 ;
int V_113 ;
V_113 = F_21 ( & V_111 , V_21 -> V_63 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_21 ( & V_112 , V_21 -> V_63 ) ;
if ( V_113 )
goto V_114;
V_113 = - V_99 ;
for ( V_57 = V_21 -> V_62 ; V_57 < V_21 -> V_62 + V_21 -> V_63 ; V_57 ++ ) {
if ( V_57 -> type != V_69 &&
V_57 -> type != V_64 )
goto V_115;
if ( V_57 -> V_65 & ~ V_116 )
goto V_115;
if ( ( V_57 -> V_65 & V_60 ) == 0 ) {
F_38 ( & V_111 , V_57 ) ;
continue;
}
if ( ! ( V_2 & V_11 ) )
goto V_115;
F_38 ( & V_112 , V_57 ) ;
if ( ! ( V_57 -> V_65 & V_61 ) )
F_38 ( & V_111 , V_57 ) ;
}
* V_25 = F_27 ( & V_111 , V_2 ) ;
if ( F_7 ( * V_25 ) ) {
V_113 = F_8 ( * V_25 ) ;
* V_25 = NULL ;
goto V_115;
}
* V_26 = F_27 ( & V_112 ,
V_2 | V_35 ) ;
if ( F_7 ( * V_26 ) ) {
V_113 = F_8 ( * V_26 ) ;
* V_26 = NULL ;
F_12 ( * V_25 ) ;
* V_25 = NULL ;
goto V_115;
}
F_20 ( * V_25 ) ;
F_20 ( * V_26 ) ;
V_113 = 0 ;
V_115:
F_24 ( & V_112 ) ;
V_114:
F_24 ( & V_111 ) ;
return V_113 ;
}
T_4
F_41 ( struct V_17 * V_18 , struct V_117 * V_118 ,
struct V_20 * V_21 )
{
T_4 error ;
int V_119 ;
struct V_19 * V_19 ;
struct V_22 * V_22 ;
struct V_24 * V_25 = NULL , * V_26 = NULL ;
unsigned int V_2 = 0 ;
error = F_42 ( V_18 , V_118 , 0 , V_120 ) ;
if ( error )
return error ;
V_19 = V_118 -> V_121 ;
V_22 = V_19 -> V_23 ;
if ( ! V_22 -> V_122 -> V_123 || ! F_43 ( V_22 ) )
return V_124 ;
if ( F_9 ( V_22 -> V_29 ) )
V_2 = V_11 ;
V_119 = F_40 ( V_21 , & V_25 , & V_26 , V_2 ) ;
if ( V_119 == - V_99 )
return V_124 ;
if ( V_119 < 0 )
goto V_125;
V_119 = V_22 -> V_122 -> V_123 ( V_22 , V_25 , V_28 ) ;
if ( V_119 < 0 )
goto V_126;
if ( F_9 ( V_22 -> V_29 ) ) {
V_119 = V_22 -> V_122 -> V_123 ( V_22 , V_26 ,
V_32 ) ;
}
V_126:
F_12 ( V_25 ) ;
F_12 ( V_26 ) ;
V_125:
if ( V_119 == - V_127 )
return V_124 ;
else
return F_44 ( V_119 ) ;
}
static short
F_39 ( struct V_56 * V_57 )
{
switch ( V_57 -> V_67 ) {
case V_70 :
return ( V_57 -> V_65 & V_74 ?
V_50 : V_48 ) ;
case V_68 :
return V_43 ;
case V_73 :
return V_46 ;
case V_77 :
return V_52 ;
}
F_45 () ;
return - 1 ;
}
struct V_20 *
F_10 ( int V_104 )
{
struct V_20 * V_21 ;
V_21 = F_46 ( sizeof( * V_21 ) + V_104 * sizeof( struct V_56 ) , V_30 ) ;
if ( V_21 == NULL )
return NULL ;
V_21 -> V_63 = 0 ;
return V_21 ;
}
int
F_47 ( char * V_128 , T_1 V_129 )
{
int V_83 ;
for ( V_83 = 0 ; V_83 < F_48 ( V_130 ) ; V_83 ++ ) {
if ( V_130 [ V_83 ] . V_131 == V_129 &&
0 == memcmp ( V_130 [ V_83 ] . string , V_128 , V_129 ) )
return V_130 [ V_83 ] . type ;
}
return V_70 ;
}
T_4 F_49 ( int V_132 , T_4 * * V_128 , int * V_129 )
{
int V_83 ;
int V_133 ;
for ( V_83 = 0 ; V_83 < F_48 ( V_130 ) ; V_83 ++ ) {
if ( V_130 [ V_83 ] . type != V_132 )
continue;
V_133 = 4 + ( F_50 ( V_130 [ V_83 ] . V_131 ) << 2 ) ;
if ( V_133 > * V_129 )
return V_134 ;
* V_128 = F_51 ( * V_128 , V_130 [ V_83 ] . string ,
V_130 [ V_83 ] . V_131 ) ;
* V_129 -= V_133 ;
return 0 ;
}
F_52 ( 1 ) ;
return - 1 ;
}
