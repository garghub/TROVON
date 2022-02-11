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
struct V_17 *
F_4 ( struct V_18 * V_19 , struct V_18 * V_20 ,
unsigned int V_2 )
{
struct V_17 * V_21 ;
int V_22 = 0 ;
if ( V_19 ) {
if ( F_5 ( V_19 ) < 0 )
return F_6 ( - V_23 ) ;
V_22 += 2 * V_19 -> V_24 ;
}
if ( V_20 ) {
if ( F_5 ( V_20 ) < 0 )
return F_6 ( - V_23 ) ;
V_22 += 2 * V_20 -> V_24 ;
}
V_21 = F_7 ( V_22 ) ;
if ( V_21 == NULL )
return F_6 ( - V_25 ) ;
if ( V_19 )
F_8 ( V_19 , V_21 , V_2 & ~ V_26 ) ;
if ( V_20 )
F_8 ( V_20 , V_21 , V_2 | V_26 ) ;
return V_21 ;
}
static void
F_9 ( struct V_18 * V_21 , struct V_27 * V_28 )
{
struct V_29 * V_30 , * V_31 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_3 = 07 ;
V_31 = V_21 -> V_32 + V_21 -> V_24 ;
F_10 (pa, acl, pe) {
switch ( V_30 -> V_33 ) {
case V_34 :
V_28 -> V_35 = V_30 -> V_36 ;
break;
case V_37 :
V_28 -> V_38 = V_30 -> V_36 ;
break;
case V_39 :
V_28 -> V_40 |= V_30 -> V_36 ;
break;
case V_41 :
V_28 -> V_42 |= V_30 -> V_36 ;
break;
case V_43 :
V_28 -> V_44 = V_30 -> V_36 ;
break;
case V_45 :
V_28 -> V_3 = V_30 -> V_36 ;
break;
}
}
V_28 -> V_40 &= V_28 -> V_3 ;
V_28 -> V_38 &= V_28 -> V_3 ;
V_28 -> V_42 &= V_28 -> V_3 ;
}
static void
F_8 ( struct V_18 * V_19 , struct V_17 * V_21 ,
unsigned int V_2 )
{
struct V_29 * V_30 , * V_46 ;
struct V_47 * V_48 ;
struct V_27 V_28 ;
unsigned short V_49 ;
int V_50 = ( ( V_2 & V_26 ) ?
V_51 | V_52 : 0 ) ;
F_11 ( V_19 -> V_24 < 3 ) ;
F_9 ( V_19 , & V_28 ) ;
V_30 = V_19 -> V_32 ;
V_48 = V_21 -> V_53 + V_21 -> V_54 ;
V_49 = ~ V_28 . V_35 ;
V_49 &= V_28 . V_40 | V_28 . V_38 | V_28 . V_42 | V_28 . V_44 ;
if ( V_49 ) {
V_48 -> type = V_55 ;
V_48 -> V_56 = V_50 ;
V_48 -> V_57 = F_2 ( V_49 , V_2 ) ;
V_48 -> V_58 = V_59 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
}
V_48 -> type = V_60 ;
V_48 -> V_56 = V_50 ;
V_48 -> V_57 = F_1 ( V_30 -> V_36 , V_2 | V_5 ) ;
V_48 -> V_58 = V_59 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
V_30 ++ ;
while ( V_30 -> V_33 == V_39 ) {
V_49 = ~ ( V_30 -> V_36 & V_28 . V_3 ) ;
V_49 &= V_28 . V_42 | V_28 . V_38 | V_28 . V_44 ;
if ( V_49 ) {
V_48 -> type = V_55 ;
V_48 -> V_56 = V_50 ;
V_48 -> V_57 = F_2 ( V_49 , V_2 ) ;
V_48 -> V_58 = V_61 ;
V_48 -> V_62 = V_30 -> V_63 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
}
V_48 -> type = V_60 ;
V_48 -> V_56 = V_50 ;
V_48 -> V_57 = F_1 ( V_30 -> V_36 & V_28 . V_3 ,
V_2 ) ;
V_48 -> V_58 = V_61 ;
V_48 -> V_62 = V_30 -> V_63 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
V_30 ++ ;
}
V_46 = V_30 ;
V_48 -> type = V_60 ;
V_48 -> V_56 = V_50 ;
V_48 -> V_57 = F_1 ( V_28 . V_38 , V_2 ) ;
V_48 -> V_58 = V_64 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
V_30 ++ ;
while ( V_30 -> V_33 == V_41 ) {
V_48 -> type = V_60 ;
V_48 -> V_56 = V_50 | V_65 ;
V_48 -> V_57 = F_1 ( V_30 -> V_36 & V_28 . V_3 ,
V_2 ) ;
V_48 -> V_58 = V_61 ;
V_48 -> V_66 = V_30 -> V_67 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
V_30 ++ ;
}
V_30 = V_46 ;
V_49 = ~ V_28 . V_38 & V_28 . V_44 ;
if ( V_49 ) {
V_48 -> type = V_55 ;
V_48 -> V_56 = V_50 ;
V_48 -> V_57 = F_2 ( V_49 , V_2 ) ;
V_48 -> V_58 = V_64 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
}
V_30 ++ ;
while ( V_30 -> V_33 == V_41 ) {
V_49 = ~ ( V_30 -> V_36 & V_28 . V_3 ) ;
V_49 &= V_28 . V_44 ;
if ( V_49 ) {
V_48 -> type = V_55 ;
V_48 -> V_56 = V_50 | V_65 ;
V_48 -> V_57 = F_2 ( V_49 , V_2 ) ;
V_48 -> V_58 = V_61 ;
V_48 -> V_66 = V_30 -> V_67 ;
V_48 ++ ;
V_21 -> V_54 ++ ;
}
V_30 ++ ;
}
if ( V_30 -> V_33 == V_45 )
V_30 ++ ;
V_48 -> type = V_60 ;
V_48 -> V_56 = V_50 ;
V_48 -> V_57 = F_1 ( V_30 -> V_36 , V_2 ) ;
V_48 -> V_58 = V_68 ;
V_21 -> V_54 ++ ;
}
static bool
F_12 ( struct V_29 * V_69 , struct V_29 * V_70 )
{
if ( V_69 -> V_33 != V_70 -> V_33 )
return V_69 -> V_33 > V_70 -> V_33 ;
if ( V_69 -> V_33 == V_39 )
return F_13 ( V_69 -> V_63 , V_70 -> V_63 ) ;
if ( V_69 -> V_33 == V_41 )
return F_14 ( V_69 -> V_67 , V_70 -> V_67 ) ;
return false ;
}
static void
F_15 ( struct V_18 * V_19 , int V_71 , int V_72 ) {
int V_73 = 0 , V_74 ;
struct V_29 V_75 ;
while ( ! V_73 ) {
V_73 = 1 ;
for ( V_74 = V_71 ; V_74 < V_72 ; V_74 ++ ) {
if ( F_12 ( & V_19 -> V_32 [ V_74 ] ,
& V_19 -> V_32 [ V_74 + 1 ] ) ) {
V_73 = 0 ;
V_75 = V_19 -> V_32 [ V_74 ] ;
V_19 -> V_32 [ V_74 ] = V_19 -> V_32 [ V_74 + 1 ] ;
V_19 -> V_32 [ V_74 + 1 ] = V_75 ;
}
}
}
}
static void
F_16 ( struct V_18 * V_19 )
{
int V_74 , V_76 ;
if ( V_19 -> V_24 <= 4 )
return;
V_74 = 1 ;
while ( V_19 -> V_32 [ V_74 ] . V_33 == V_39 )
V_74 ++ ;
F_15 ( V_19 , 1 , V_74 - 1 ) ;
F_11 ( V_19 -> V_32 [ V_74 ] . V_33 != V_37 ) ;
V_76 = ++ V_74 ;
while ( V_19 -> V_32 [ V_76 ] . V_33 == V_41 )
V_76 ++ ;
F_15 ( V_19 , V_74 , V_76 - 1 ) ;
return;
}
static int
F_17 ( struct V_77 * V_78 , int V_79 )
{
int V_80 ;
memset ( V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 -> V_81 = 1 ;
V_80 = sizeof( struct V_82 )
+ V_79 * sizeof( struct V_83 ) ;
V_78 -> V_40 = F_18 ( V_80 , V_84 ) ;
if ( ! V_78 -> V_40 )
return - V_25 ;
V_78 -> V_42 = F_18 ( V_80 , V_84 ) ;
if ( ! V_78 -> V_42 ) {
F_19 ( V_78 -> V_40 ) ;
return - V_25 ;
}
return 0 ;
}
static void
F_20 ( struct V_77 * V_78 ) {
F_19 ( V_78 -> V_40 ) ;
F_19 ( V_78 -> V_42 ) ;
}
static inline void F_21 ( struct V_77 * V_78 , struct V_85 * V_86 )
{
V_78 -> V_3 . V_87 |= V_86 -> V_87 ;
}
static inline int F_22 ( T_1 V_3 , int V_88 )
{
if ( V_3 & ( V_89 | V_90 ) )
return - V_23 ;
if ( ! V_88 )
return 0 ;
if ( V_3 & ( V_91 | V_92 ) )
return - V_23 ;
return 0 ;
}
static struct V_18 *
F_23 ( struct V_77 * V_78 , unsigned int V_2 )
{
struct V_29 * V_93 ;
struct V_18 * V_19 ;
int V_94 ;
int V_74 , error = 0 ;
if ( V_78 -> V_81 && ( V_2 & V_26 ) ) {
V_19 = F_24 ( 0 , V_84 ) ;
return V_19 ? V_19 : F_6 ( - V_25 ) ;
}
V_94 = 4 + V_78 -> V_40 -> V_95 + V_78 -> V_42 -> V_95 ;
V_19 = F_24 ( V_94 , V_84 ) ;
if ( ! V_19 )
return F_6 ( - V_25 ) ;
V_93 = V_19 -> V_32 ;
V_93 -> V_33 = V_34 ;
error = F_22 ( V_78 -> V_35 . V_49 , 1 ) ;
if ( error )
goto V_96;
F_3 ( V_78 -> V_35 . V_87 , & V_93 -> V_36 , V_2 ) ;
for ( V_74 = 0 ; V_74 < V_78 -> V_40 -> V_95 ; V_74 ++ ) {
V_93 ++ ;
V_93 -> V_33 = V_39 ;
error = F_22 ( V_78 -> V_40 -> V_53 [ V_74 ] . V_97 . V_49 , 0 ) ;
if ( error )
goto V_96;
F_3 ( V_78 -> V_40 -> V_53 [ V_74 ] . V_97 . V_87 ,
& V_93 -> V_36 , V_2 ) ;
V_93 -> V_63 = V_78 -> V_40 -> V_53 [ V_74 ] . V_98 ;
F_21 ( V_78 , & V_78 -> V_40 -> V_53 [ V_74 ] . V_97 ) ;
}
V_93 ++ ;
V_93 -> V_33 = V_37 ;
error = F_22 ( V_78 -> V_38 . V_49 , 0 ) ;
if ( error )
goto V_96;
F_3 ( V_78 -> V_38 . V_87 , & V_93 -> V_36 , V_2 ) ;
F_21 ( V_78 , & V_78 -> V_38 ) ;
for ( V_74 = 0 ; V_74 < V_78 -> V_42 -> V_95 ; V_74 ++ ) {
V_93 ++ ;
V_93 -> V_33 = V_41 ;
error = F_22 ( V_78 -> V_42 -> V_53 [ V_74 ] . V_97 . V_49 , 0 ) ;
if ( error )
goto V_96;
F_3 ( V_78 -> V_42 -> V_53 [ V_74 ] . V_97 . V_87 ,
& V_93 -> V_36 , V_2 ) ;
V_93 -> V_67 = V_78 -> V_42 -> V_53 [ V_74 ] . V_99 ;
F_21 ( V_78 , & V_78 -> V_42 -> V_53 [ V_74 ] . V_97 ) ;
}
V_93 ++ ;
V_93 -> V_33 = V_45 ;
F_3 ( V_78 -> V_3 . V_87 , & V_93 -> V_36 , V_2 ) ;
V_93 ++ ;
V_93 -> V_33 = V_43 ;
error = F_22 ( V_78 -> V_44 . V_49 , 0 ) ;
if ( error )
goto V_96;
F_3 ( V_78 -> V_44 . V_87 , & V_93 -> V_36 , V_2 ) ;
return V_19 ;
V_96:
F_25 ( V_19 ) ;
return F_6 ( error ) ;
}
static inline void F_26 ( struct V_85 * V_86 , T_1 V_3 )
{
V_86 -> V_87 |= V_3 & ~ V_86 -> V_49 ;
}
static inline void F_27 ( struct V_85 * V_86 , T_1 V_3 )
{
V_86 -> V_49 |= V_3 & ~ V_86 -> V_87 ;
}
static int F_28 ( struct V_77 * V_78 , T_2 V_98 )
{
struct V_82 * V_100 = V_78 -> V_40 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_100 -> V_95 ; V_74 ++ )
if ( F_29 ( V_100 -> V_53 [ V_74 ] . V_98 , V_98 ) )
return V_74 ;
V_100 -> V_95 ++ ;
V_100 -> V_53 [ V_74 ] . V_98 = V_98 ;
V_100 -> V_53 [ V_74 ] . V_97 . V_87 = V_78 -> V_101 . V_87 ;
V_100 -> V_53 [ V_74 ] . V_97 . V_49 = V_78 -> V_101 . V_49 ;
return V_74 ;
}
static int F_30 ( struct V_77 * V_78 , T_3 V_99 )
{
struct V_82 * V_100 = V_78 -> V_42 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_100 -> V_95 ; V_74 ++ )
if ( F_31 ( V_100 -> V_53 [ V_74 ] . V_99 , V_99 ) )
return V_74 ;
V_100 -> V_95 ++ ;
V_100 -> V_53 [ V_74 ] . V_99 = V_99 ;
V_100 -> V_53 [ V_74 ] . V_97 . V_87 = V_78 -> V_101 . V_87 ;
V_100 -> V_53 [ V_74 ] . V_97 . V_49 = V_78 -> V_101 . V_49 ;
return V_74 ;
}
static void F_32 ( struct V_82 * V_100 , T_1 V_3 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_100 -> V_95 ; V_74 ++ )
F_27 ( & V_100 -> V_53 [ V_74 ] . V_97 , V_3 ) ;
}
static void F_33 ( struct V_82 * V_100 , T_1 V_3 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_100 -> V_95 ; V_74 ++ )
F_26 ( & V_100 -> V_53 [ V_74 ] . V_97 , V_3 ) ;
}
static void F_34 ( struct V_77 * V_78 ,
struct V_47 * V_48 )
{
T_1 V_3 = V_48 -> V_57 ;
int V_74 ;
V_78 -> V_81 = 0 ;
switch ( F_35 ( V_48 ) ) {
case V_34 :
if ( V_48 -> type == V_60 ) {
F_26 ( & V_78 -> V_35 , V_3 ) ;
} else {
F_27 ( & V_78 -> V_35 , V_3 ) ;
}
break;
case V_39 :
V_74 = F_28 ( V_78 , V_48 -> V_62 ) ;
if ( V_48 -> type == V_60 ) {
F_26 ( & V_78 -> V_40 -> V_53 [ V_74 ] . V_97 , V_3 ) ;
} else {
F_27 ( & V_78 -> V_40 -> V_53 [ V_74 ] . V_97 , V_3 ) ;
V_3 = V_78 -> V_40 -> V_53 [ V_74 ] . V_97 . V_49 ;
F_27 ( & V_78 -> V_35 , V_3 ) ;
}
break;
case V_37 :
if ( V_48 -> type == V_60 ) {
F_26 ( & V_78 -> V_38 , V_3 ) ;
} else {
F_27 ( & V_78 -> V_38 , V_3 ) ;
V_3 = V_78 -> V_38 . V_49 ;
F_27 ( & V_78 -> V_35 , V_3 ) ;
F_27 ( & V_78 -> V_101 , V_3 ) ;
F_32 ( V_78 -> V_40 , V_3 ) ;
F_32 ( V_78 -> V_42 , V_3 ) ;
}
break;
case V_41 :
V_74 = F_30 ( V_78 , V_48 -> V_66 ) ;
if ( V_48 -> type == V_60 ) {
F_26 ( & V_78 -> V_42 -> V_53 [ V_74 ] . V_97 , V_3 ) ;
} else {
F_27 ( & V_78 -> V_42 -> V_53 [ V_74 ] . V_97 , V_3 ) ;
V_3 = V_78 -> V_42 -> V_53 [ V_74 ] . V_97 . V_49 ;
F_27 ( & V_78 -> V_35 , V_3 ) ;
F_27 ( & V_78 -> V_38 , V_3 ) ;
F_27 ( & V_78 -> V_101 , V_3 ) ;
F_32 ( V_78 -> V_40 , V_3 ) ;
F_32 ( V_78 -> V_42 , V_3 ) ;
}
break;
case V_43 :
if ( V_48 -> type == V_60 ) {
F_26 ( & V_78 -> V_35 , V_3 ) ;
F_26 ( & V_78 -> V_38 , V_3 ) ;
F_26 ( & V_78 -> V_44 , V_3 ) ;
F_26 ( & V_78 -> V_101 , V_3 ) ;
F_33 ( V_78 -> V_40 , V_3 ) ;
F_33 ( V_78 -> V_42 , V_3 ) ;
} else {
F_27 ( & V_78 -> V_35 , V_3 ) ;
F_27 ( & V_78 -> V_38 , V_3 ) ;
F_27 ( & V_78 -> V_44 , V_3 ) ;
F_27 ( & V_78 -> V_101 , V_3 ) ;
F_32 ( V_78 -> V_40 , V_3 ) ;
F_32 ( V_78 -> V_42 , V_3 ) ;
}
}
}
int F_36 ( struct V_17 * V_21 , struct V_18 * * V_19 ,
struct V_18 * * V_20 , unsigned int V_2 )
{
struct V_77 V_102 , V_103 ;
struct V_47 * V_48 ;
int V_104 ;
V_104 = F_17 ( & V_102 , V_21 -> V_54 ) ;
if ( V_104 )
return V_104 ;
V_104 = F_17 ( & V_103 , V_21 -> V_54 ) ;
if ( V_104 )
goto V_105;
V_104 = - V_23 ;
for ( V_48 = V_21 -> V_53 ; V_48 < V_21 -> V_53 + V_21 -> V_54 ; V_48 ++ ) {
if ( V_48 -> type != V_60 &&
V_48 -> type != V_55 )
goto V_106;
if ( V_48 -> V_56 & ~ V_107 )
goto V_106;
if ( ( V_48 -> V_56 & V_51 ) == 0 ) {
F_34 ( & V_102 , V_48 ) ;
continue;
}
if ( ! ( V_2 & V_11 ) )
goto V_106;
F_34 ( & V_103 , V_48 ) ;
if ( ! ( V_48 -> V_56 & V_52 ) )
F_34 ( & V_102 , V_48 ) ;
}
* V_19 = F_23 ( & V_102 , V_2 ) ;
if ( F_37 ( * V_19 ) ) {
V_104 = F_38 ( * V_19 ) ;
* V_19 = NULL ;
goto V_106;
}
* V_20 = F_23 ( & V_103 ,
V_2 | V_26 ) ;
if ( F_37 ( * V_20 ) ) {
V_104 = F_38 ( * V_20 ) ;
* V_20 = NULL ;
F_25 ( * V_19 ) ;
* V_19 = NULL ;
goto V_106;
}
F_16 ( * V_19 ) ;
F_16 ( * V_20 ) ;
V_104 = 0 ;
V_106:
F_20 ( & V_103 ) ;
V_105:
F_20 ( & V_102 ) ;
return V_104 ;
}
static short
F_35 ( struct V_47 * V_48 )
{
switch ( V_48 -> V_58 ) {
case V_61 :
return ( V_48 -> V_56 & V_65 ?
V_41 : V_39 ) ;
case V_59 :
return V_34 ;
case V_64 :
return V_37 ;
case V_68 :
return V_43 ;
}
F_39 () ;
return - 1 ;
}
struct V_17 *
F_7 ( int V_95 )
{
struct V_17 * V_21 ;
V_21 = F_40 ( sizeof( * V_21 ) + V_95 * sizeof( struct V_47 ) , V_84 ) ;
if ( V_21 == NULL )
return NULL ;
V_21 -> V_54 = 0 ;
return V_21 ;
}
int
F_41 ( char * V_108 , T_1 V_109 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < F_42 ( V_110 ) ; V_74 ++ ) {
if ( V_110 [ V_74 ] . V_111 == V_109 &&
0 == memcmp ( V_110 [ V_74 ] . string , V_108 , V_109 ) )
return V_110 [ V_74 ] . type ;
}
return V_61 ;
}
int
F_43 ( int V_112 , char * V_108 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < F_42 ( V_110 ) ; V_74 ++ ) {
if ( V_110 [ V_74 ] . type == V_112 ) {
memcpy ( V_108 , V_110 [ V_74 ] . string , V_110 [ V_74 ] . V_111 ) ;
return V_110 [ V_74 ] . V_111 ;
}
}
F_39 () ;
return - 1 ;
}
