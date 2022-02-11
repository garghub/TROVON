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
while ( ! V_82 ) {
V_82 = 1 ;
for ( V_83 = V_80 ; V_83 < V_81 ; V_83 ++ ) {
if ( F_18 ( & V_24 -> V_42 [ V_83 ] ,
& V_24 -> V_42 [ V_83 + 1 ] ) ) {
V_82 = 0 ;
F_22 ( V_24 -> V_42 [ V_83 ] ,
V_24 -> V_42 [ V_83 + 1 ] ) ;
}
}
}
}
static void
F_23 ( struct V_23 * V_24 )
{
int V_83 , V_84 ;
if ( ! V_24 || V_24 -> V_30 <= 4 )
return;
V_83 = 1 ;
while ( V_24 -> V_42 [ V_83 ] . V_43 == V_49 )
V_83 ++ ;
F_21 ( V_24 , 1 , V_83 - 1 ) ;
F_17 ( V_24 -> V_42 [ V_83 ] . V_43 != V_47 ) ;
V_84 = ++ V_83 ;
while ( V_24 -> V_42 [ V_84 ] . V_43 == V_51 )
V_84 ++ ;
F_21 ( V_24 , V_83 , V_84 - 1 ) ;
return;
}
static int
F_24 ( struct V_85 * V_86 , int V_87 )
{
int V_88 ;
memset ( V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 -> V_89 = 1 ;
V_88 = sizeof( struct V_90 )
+ V_87 * sizeof( struct V_91 ) ;
V_86 -> V_50 = F_25 ( V_88 , V_29 ) ;
if ( ! V_86 -> V_50 )
return - V_33 ;
V_86 -> V_52 = F_25 ( V_88 , V_29 ) ;
if ( ! V_86 -> V_52 ) {
F_26 ( V_86 -> V_50 ) ;
return - V_33 ;
}
return 0 ;
}
static void
F_27 ( struct V_85 * V_86 ) {
F_26 ( V_86 -> V_50 ) ;
F_26 ( V_86 -> V_52 ) ;
}
static inline void F_28 ( struct V_85 * V_86 , struct V_92 * V_93 )
{
V_86 -> V_3 . V_94 |= V_93 -> V_94 ;
}
static struct V_23 *
F_29 ( struct V_85 * V_86 , unsigned int V_2 )
{
struct V_39 * V_95 ;
struct V_23 * V_24 ;
int V_96 ;
int V_83 ;
if ( V_86 -> V_89 && ( V_2 & V_36 ) )
return NULL ;
if ( ! V_86 -> V_50 -> V_97 && ! V_86 -> V_52 -> V_97 )
V_96 = 3 ;
else
V_96 = 4 + V_86 -> V_50 -> V_97 + V_86 -> V_52 -> V_97 ;
V_24 = F_30 ( V_96 , V_29 ) ;
if ( ! V_24 )
return F_31 ( - V_33 ) ;
V_95 = V_24 -> V_42 ;
V_95 -> V_43 = V_44 ;
F_3 ( V_86 -> V_45 . V_94 , & V_95 -> V_46 , V_2 ) ;
for ( V_83 = 0 ; V_83 < V_86 -> V_50 -> V_97 ; V_83 ++ ) {
V_95 ++ ;
V_95 -> V_43 = V_49 ;
F_3 ( V_86 -> V_50 -> V_63 [ V_83 ] . V_98 . V_94 ,
& V_95 -> V_46 , V_2 ) ;
V_95 -> V_72 = V_86 -> V_50 -> V_63 [ V_83 ] . V_99 ;
F_28 ( V_86 , & V_86 -> V_50 -> V_63 [ V_83 ] . V_98 ) ;
}
V_95 ++ ;
V_95 -> V_43 = V_47 ;
F_3 ( V_86 -> V_48 . V_94 , & V_95 -> V_46 , V_2 ) ;
F_28 ( V_86 , & V_86 -> V_48 ) ;
for ( V_83 = 0 ; V_83 < V_86 -> V_52 -> V_97 ; V_83 ++ ) {
V_95 ++ ;
V_95 -> V_43 = V_51 ;
F_3 ( V_86 -> V_52 -> V_63 [ V_83 ] . V_98 . V_94 ,
& V_95 -> V_46 , V_2 ) ;
V_95 -> V_76 = V_86 -> V_52 -> V_63 [ V_83 ] . V_100 ;
F_28 ( V_86 , & V_86 -> V_52 -> V_63 [ V_83 ] . V_98 ) ;
}
if ( V_86 -> V_50 -> V_97 || V_86 -> V_52 -> V_97 ) {
V_95 ++ ;
V_95 -> V_43 = V_55 ;
F_3 ( V_86 -> V_3 . V_94 , & V_95 -> V_46 , V_2 ) ;
}
V_95 ++ ;
V_95 -> V_43 = V_53 ;
F_3 ( V_86 -> V_54 . V_94 , & V_95 -> V_46 , V_2 ) ;
return V_24 ;
}
static inline void F_32 ( struct V_92 * V_93 , T_1 V_3 )
{
V_93 -> V_94 |= V_3 & ~ V_93 -> V_59 ;
}
static inline void F_33 ( struct V_92 * V_93 , T_1 V_3 )
{
V_93 -> V_59 |= V_3 & ~ V_93 -> V_94 ;
}
static int F_34 ( struct V_85 * V_86 , T_2 V_99 )
{
struct V_90 * V_101 = V_86 -> V_50 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_101 -> V_97 ; V_83 ++ )
if ( F_35 ( V_101 -> V_63 [ V_83 ] . V_99 , V_99 ) )
return V_83 ;
V_101 -> V_97 ++ ;
V_101 -> V_63 [ V_83 ] . V_99 = V_99 ;
V_101 -> V_63 [ V_83 ] . V_98 . V_94 = V_86 -> V_102 . V_94 ;
V_101 -> V_63 [ V_83 ] . V_98 . V_59 = V_86 -> V_102 . V_59 ;
return V_83 ;
}
static int F_36 ( struct V_85 * V_86 , T_3 V_100 )
{
struct V_90 * V_101 = V_86 -> V_52 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_101 -> V_97 ; V_83 ++ )
if ( F_37 ( V_101 -> V_63 [ V_83 ] . V_100 , V_100 ) )
return V_83 ;
V_101 -> V_97 ++ ;
V_101 -> V_63 [ V_83 ] . V_100 = V_100 ;
V_101 -> V_63 [ V_83 ] . V_98 . V_94 = V_86 -> V_102 . V_94 ;
V_101 -> V_63 [ V_83 ] . V_98 . V_59 = V_86 -> V_102 . V_59 ;
return V_83 ;
}
static void F_38 ( struct V_90 * V_101 , T_1 V_3 )
{
int V_83 ;
for ( V_83 = 0 ; V_83 < V_101 -> V_97 ; V_83 ++ )
F_33 ( & V_101 -> V_63 [ V_83 ] . V_98 , V_3 ) ;
}
static void F_39 ( struct V_90 * V_101 , T_1 V_3 )
{
int V_83 ;
for ( V_83 = 0 ; V_83 < V_101 -> V_97 ; V_83 ++ )
F_32 ( & V_101 -> V_63 [ V_83 ] . V_98 , V_3 ) ;
}
static void F_40 ( struct V_85 * V_86 ,
struct V_57 * V_58 )
{
T_1 V_3 = V_58 -> V_66 ;
int V_83 ;
V_86 -> V_89 = 0 ;
switch ( F_41 ( V_58 ) ) {
case V_44 :
if ( V_58 -> type == V_69 ) {
F_32 ( & V_86 -> V_45 , V_3 ) ;
} else {
F_33 ( & V_86 -> V_45 , V_3 ) ;
}
break;
case V_49 :
V_83 = F_34 ( V_86 , V_58 -> V_71 ) ;
if ( V_58 -> type == V_69 ) {
F_32 ( & V_86 -> V_50 -> V_63 [ V_83 ] . V_98 , V_3 ) ;
} else {
F_33 ( & V_86 -> V_50 -> V_63 [ V_83 ] . V_98 , V_3 ) ;
V_3 = V_86 -> V_50 -> V_63 [ V_83 ] . V_98 . V_59 ;
F_33 ( & V_86 -> V_45 , V_3 ) ;
}
break;
case V_47 :
if ( V_58 -> type == V_69 ) {
F_32 ( & V_86 -> V_48 , V_3 ) ;
} else {
F_33 ( & V_86 -> V_48 , V_3 ) ;
V_3 = V_86 -> V_48 . V_59 ;
F_33 ( & V_86 -> V_45 , V_3 ) ;
F_33 ( & V_86 -> V_102 , V_3 ) ;
F_38 ( V_86 -> V_50 , V_3 ) ;
F_38 ( V_86 -> V_52 , V_3 ) ;
}
break;
case V_51 :
V_83 = F_36 ( V_86 , V_58 -> V_75 ) ;
if ( V_58 -> type == V_69 ) {
F_32 ( & V_86 -> V_52 -> V_63 [ V_83 ] . V_98 , V_3 ) ;
} else {
F_33 ( & V_86 -> V_52 -> V_63 [ V_83 ] . V_98 , V_3 ) ;
V_3 = V_86 -> V_52 -> V_63 [ V_83 ] . V_98 . V_59 ;
F_33 ( & V_86 -> V_45 , V_3 ) ;
F_33 ( & V_86 -> V_48 , V_3 ) ;
F_33 ( & V_86 -> V_102 , V_3 ) ;
F_38 ( V_86 -> V_50 , V_3 ) ;
F_38 ( V_86 -> V_52 , V_3 ) ;
}
break;
case V_53 :
if ( V_58 -> type == V_69 ) {
F_32 ( & V_86 -> V_45 , V_3 ) ;
F_32 ( & V_86 -> V_48 , V_3 ) ;
F_32 ( & V_86 -> V_54 , V_3 ) ;
F_32 ( & V_86 -> V_102 , V_3 ) ;
F_39 ( V_86 -> V_50 , V_3 ) ;
F_39 ( V_86 -> V_52 , V_3 ) ;
} else {
F_33 ( & V_86 -> V_45 , V_3 ) ;
F_33 ( & V_86 -> V_48 , V_3 ) ;
F_33 ( & V_86 -> V_54 , V_3 ) ;
F_33 ( & V_86 -> V_102 , V_3 ) ;
F_38 ( V_86 -> V_50 , V_3 ) ;
F_38 ( V_86 -> V_52 , V_3 ) ;
}
}
}
static int F_42 ( struct V_20 * V_21 ,
struct V_23 * * V_24 , struct V_23 * * V_25 ,
unsigned int V_2 )
{
struct V_85 V_103 , V_104 ;
struct V_57 * V_58 ;
int V_105 ;
V_105 = F_24 ( & V_103 , V_21 -> V_35 ) ;
if ( V_105 )
return V_105 ;
V_105 = F_24 ( & V_104 , V_21 -> V_35 ) ;
if ( V_105 )
goto V_106;
V_105 = - V_107 ;
for ( V_58 = V_21 -> V_63 ; V_58 < V_21 -> V_63 + V_21 -> V_35 ; V_58 ++ ) {
if ( V_58 -> type != V_69 &&
V_58 -> type != V_64 )
goto V_108;
if ( V_58 -> V_65 & ~ V_109 )
goto V_108;
if ( ( V_58 -> V_65 & V_61 ) == 0 ) {
F_40 ( & V_103 , V_58 ) ;
continue;
}
if ( ! ( V_2 & V_11 ) )
goto V_108;
F_40 ( & V_104 , V_58 ) ;
if ( ! ( V_58 -> V_65 & V_62 ) )
F_40 ( & V_103 , V_58 ) ;
}
* V_24 = F_29 ( & V_103 , V_2 ) ;
if ( F_8 ( * V_24 ) ) {
V_105 = F_9 ( * V_24 ) ;
* V_24 = NULL ;
goto V_108;
}
* V_25 = F_29 ( & V_104 ,
V_2 | V_36 ) ;
if ( F_8 ( * V_25 ) ) {
V_105 = F_9 ( * V_25 ) ;
* V_25 = NULL ;
F_14 ( * V_24 ) ;
* V_24 = NULL ;
goto V_108;
}
F_23 ( * V_24 ) ;
F_23 ( * V_25 ) ;
V_105 = 0 ;
V_108:
F_27 ( & V_104 ) ;
V_106:
F_27 ( & V_103 ) ;
return V_105 ;
}
T_4
F_43 ( struct V_17 * V_18 , struct V_110 * V_111 ,
struct V_20 * V_21 )
{
T_4 error ;
int V_112 ;
struct V_19 * V_19 ;
struct V_22 * V_22 ;
struct V_23 * V_24 = NULL , * V_25 = NULL ;
unsigned int V_2 = 0 ;
error = F_44 ( V_18 , V_111 , 0 , V_113 ) ;
if ( error )
return error ;
V_19 = V_111 -> V_114 ;
V_22 = F_5 ( V_19 ) ;
if ( F_10 ( V_22 -> V_28 ) )
V_2 = V_11 ;
V_112 = F_42 ( V_21 , & V_24 , & V_25 , V_2 ) ;
if ( V_112 == - V_107 )
return V_115 ;
if ( V_112 < 0 )
goto V_116;
F_45 ( V_111 ) ;
V_112 = F_46 ( V_22 , V_27 , V_24 ) ;
if ( V_112 < 0 )
goto V_117;
if ( F_10 ( V_22 -> V_28 ) ) {
V_112 = F_46 ( V_22 , V_31 , V_25 ) ;
}
V_117:
F_47 ( V_111 ) ;
F_14 ( V_24 ) ;
F_14 ( V_25 ) ;
V_116:
if ( V_112 == - V_118 )
return V_115 ;
else
return F_48 ( V_112 ) ;
}
static short
F_41 ( struct V_57 * V_58 )
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
F_49 () ;
return - 1 ;
}
int F_12 ( int V_119 )
{
return sizeof( struct V_20 ) + V_119 * sizeof( struct V_57 ) ;
}
int
F_50 ( char * V_120 , T_1 V_121 )
{
int V_83 ;
for ( V_83 = 0 ; V_83 < F_51 ( V_122 ) ; V_83 ++ ) {
if ( V_122 [ V_83 ] . V_123 == V_121 &&
0 == memcmp ( V_122 [ V_83 ] . string , V_120 , V_121 ) )
return V_122 [ V_83 ] . type ;
}
return V_70 ;
}
T_4 F_52 ( struct V_124 * V_125 , int V_126 )
{
T_4 * V_120 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < F_51 ( V_122 ) ; V_83 ++ ) {
if ( V_122 [ V_83 ] . type != V_126 )
continue;
V_120 = F_53 ( V_125 , V_122 [ V_83 ] . V_123 + 4 ) ;
if ( ! V_120 )
return V_127 ;
V_120 = F_54 ( V_120 , V_122 [ V_83 ] . string ,
V_122 [ V_83 ] . V_123 ) ;
return 0 ;
}
F_55 ( 1 ) ;
return V_128 ;
}
