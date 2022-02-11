static unsigned int F_1 ( unsigned int V_1 )
{
return 1U << V_1 ;
}
static unsigned int F_2 ( unsigned int V_2 )
{
return F_3 ( V_2 ) - 1 ;
}
struct V_3 * F_4 ( struct V_4 * V_5 )
{
struct V_3 * V_6 ;
V_6 = F_5 ( V_5 , V_7 ) ;
if ( ! V_6 )
F_6 ( V_8 , L_1 , V_9 ) ;
return V_6 ;
}
static int F_7 ( struct V_10 * V_11 , struct V_3 * V_6 ,
unsigned int V_12 )
{
F_8 ( V_11 , - V_13 ) ;
F_9 ( F_10 ( V_11 ) , 0 , - V_13 ,
L_2 ) ;
if ( V_12 == 0 ) {
F_6 ( V_8 , L_3 ) ;
return - V_13 ;
}
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_11 ( & V_6 -> V_14 ) ;
F_12 ( & V_6 -> V_15 ) ;
V_6 -> V_11 = V_11 ;
V_6 -> V_16 = NULL ;
V_6 -> V_17 = V_18 ;
V_6 -> V_19 = V_11 -> V_19 ;
V_6 -> V_12 = V_12 ;
V_6 -> V_20 = V_6 -> V_19 + F_13 ( V_12 ) ;
V_6 -> V_21 = NULL ;
V_6 -> V_22 = NULL ;
return 0 ;
}
struct V_3 * F_14 (
struct V_23 * V_24 , unsigned int V_12 )
{
struct V_3 * V_25 , * V_26 , * V_27 ;
V_25 = F_15 ( V_24 , struct V_3 , V_24 ) ;
if ( V_25 -> V_12 == V_12 ||
( V_25 -> V_12 > V_12 && V_25 -> V_24 . V_28 == NULL ) ) {
goto V_29;
} else {
if ( V_25 -> V_12 < V_12 ) {
if ( ! V_25 -> V_24 . V_30 )
return NULL ;
V_26 = F_14 (
V_25 -> V_24 . V_30 , V_12 ) ;
} else {
V_26 = F_14 (
V_25 -> V_24 . V_28 , V_12 ) ;
}
if ( ! V_26 ) {
if ( V_25 -> V_12 > V_12 )
goto V_29;
else
return NULL ;
}
return V_26 ;
}
V_29:
if ( V_25 -> V_22 == NULL ) {
F_16 ( & V_25 -> V_24 , & V_25 -> V_11 -> V_31 ) ;
return V_25 ;
}
V_27 = V_25 -> V_22 ;
V_25 -> V_22 = V_27 -> V_22 ;
if ( V_27 -> V_22 )
V_27 -> V_22 -> V_21 = V_25 ;
V_27 -> V_22 = NULL ;
V_27 -> V_21 = NULL ;
return V_27 ;
}
struct V_3 * F_17 ( struct V_32 * V_33 ,
T_1 V_19 )
{
struct V_23 * V_34 = V_33 -> V_23 ;
struct V_3 * V_6 ;
do {
V_6 = F_15 ( V_34 , struct V_3 , V_24 ) ;
if ( V_6 -> V_19 > V_19 ) {
if ( V_34 -> V_28 == NULL )
return NULL ;
V_34 = V_34 -> V_28 ;
} else if ( V_6 -> V_19 < V_19 ) {
if ( V_34 -> V_30 == NULL )
return NULL ;
V_34 = V_34 -> V_30 ;
} else {
return V_6 ;
}
} while ( V_34 );
return NULL ;
}
struct V_3 * F_18 ( struct V_32 * V_33 ,
unsigned int V_19 )
{
struct V_23 * V_34 = V_33 -> V_23 ;
struct V_3 * V_6 ;
do {
V_6 = F_15 ( V_34 , struct V_3 , V_24 ) ;
if ( V_6 -> V_19 > V_19 ) {
if ( V_34 -> V_28 == NULL )
return NULL ;
V_34 = V_34 -> V_28 ;
} else {
if ( V_6 -> V_20 > V_19 )
return V_6 ;
if ( V_34 -> V_30 == NULL )
return NULL ;
V_34 = V_34 -> V_30 ;
}
} while ( V_34 );
return NULL ;
}
static void F_19 ( struct V_32 * V_33 ,
struct V_3 * V_6 )
{
struct V_23 * * V_35 = & ( V_33 -> V_23 ) ;
struct V_23 * V_36 = NULL ;
struct V_3 * V_25 ;
unsigned int V_12 = V_6 -> V_12 ;
while ( * V_35 ) {
V_36 = * V_35 ;
V_25 = F_20 ( * V_35 , struct V_3 , V_24 ) ;
if ( V_12 < V_25 -> V_12 ) {
V_35 = & ( ( * V_35 ) -> V_28 ) ;
} else if ( V_12 > V_25 -> V_12 ) {
V_35 = & ( ( * V_35 ) -> V_30 ) ;
} else {
V_6 -> V_21 = V_25 ;
V_6 -> V_22 = V_25 -> V_22 ;
if ( V_25 -> V_22 )
V_25 -> V_22 -> V_21 = V_6 ;
V_25 -> V_22 = V_6 ;
V_6 -> V_17 = ( V_6 -> V_17 & ~ V_37 ) | V_18 ;
return;
}
}
V_6 -> V_17 = ( V_6 -> V_17 & ~ V_37 ) | V_18 ;
F_21 ( & V_6 -> V_24 , V_36 , V_35 ) ;
F_22 ( & V_6 -> V_24 , V_33 ) ;
}
static void F_23 ( struct V_32 * V_33 ,
struct V_3 * V_6 )
{
struct V_23 * * V_35 = & ( V_33 -> V_23 ) ;
struct V_23 * V_36 = NULL ;
struct V_3 * V_25 ;
unsigned int V_19 = V_6 -> V_19 ;
while ( * V_35 ) {
V_36 = * V_35 ;
V_25 = F_20 ( * V_35 , struct V_3 , V_24 ) ;
if ( V_19 < V_25 -> V_19 )
V_35 = & ( ( * V_35 ) -> V_28 ) ;
else
V_35 = & ( ( * V_35 ) -> V_30 ) ;
}
F_24 ( & V_6 -> V_38 ) ;
V_6 -> V_17 = ( V_6 -> V_17 & ~ V_37 ) | V_39 ;
F_21 ( & V_6 -> V_24 , V_36 , V_35 ) ;
F_22 ( & V_6 -> V_24 , V_33 ) ;
}
struct V_3 * F_25 ( struct V_10 * V_11 ,
struct V_3 * V_6 ,
unsigned int V_12 )
{
struct V_3 * V_40 ;
unsigned long V_41 ;
int V_42 ;
V_40 = F_4 ( V_11 -> V_5 ) ;
if ( ! V_40 ) {
F_6 ( V_8 , L_4 , V_9 ) ;
return NULL ;
}
V_42 = F_7 ( V_11 , V_40 , V_12 ) ;
if ( V_42 ) {
F_6 ( V_8 , L_5 , V_9 ) ;
F_26 ( V_11 -> V_5 , V_40 ) ;
return NULL ;
}
V_40 -> V_19 = V_6 -> V_19 ;
V_40 -> V_20 = V_40 -> V_19 + F_13 ( V_12 ) ;
V_6 -> V_19 = V_40 -> V_20 ;
V_6 -> V_12 = V_6 -> V_12 - V_12 ;
F_27 ( & V_11 -> V_43 , V_41 ) ;
F_28 ( & V_40 -> V_15 , & V_6 -> V_15 ) ;
F_29 ( & V_11 -> V_43 , V_41 ) ;
return V_40 ;
}
static void F_30 ( struct V_3 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
if ( V_6 -> V_21 == NULL && V_6 -> V_22 == NULL ) {
F_16 ( & V_6 -> V_24 , & V_11 -> V_31 ) ;
} else if ( V_6 -> V_21 == NULL && V_6 -> V_22 != NULL ) {
V_6 -> V_22 -> V_21 = NULL ;
F_16 ( & V_6 -> V_24 , & V_11 -> V_31 ) ;
F_19 ( & V_11 -> V_31 , V_6 -> V_22 ) ;
V_6 -> V_22 = NULL ;
} else if ( V_6 -> V_21 != NULL && V_6 -> V_22 == NULL ) {
V_6 -> V_21 -> V_22 = NULL ;
V_6 -> V_21 = NULL ;
} else {
V_6 -> V_22 -> V_21 = V_6 -> V_21 ;
V_6 -> V_21 -> V_22 = V_6 -> V_22 ;
V_6 -> V_22 = NULL ;
V_6 -> V_21 = NULL ;
}
}
struct V_3 * F_31 ( struct V_3 * V_6 ,
struct V_3 * V_44 )
{
struct V_10 * V_11 ;
unsigned long V_41 ;
V_11 = V_6 -> V_11 ;
V_44 -> V_19 = V_6 -> V_19 ;
V_44 -> V_12 = V_44 -> V_12 + V_6 -> V_12 ;
F_27 ( & V_11 -> V_43 , V_41 ) ;
F_32 ( & V_6 -> V_15 ) ;
F_29 ( & V_11 -> V_43 , V_41 ) ;
F_26 ( V_6 -> V_11 -> V_5 , V_6 ) ;
return V_44 ;
}
int F_33 ( struct V_10 * V_11 ,
struct V_45 * V_46 ,
unsigned int V_47 ,
unsigned int V_48 )
{
struct V_3 * V_6 ;
unsigned long V_41 ;
int V_42 ;
F_8 ( V_11 , - V_13 ) ;
V_42 = F_34 ( & V_11 -> V_49 , V_46 ) ;
if ( V_42 ) {
F_6 ( V_8 , L_6 ) ;
return V_42 ;
}
V_11 -> V_19 = V_47 ;
V_11 -> V_12 = F_35 ( V_48 ) ;
V_11 -> V_48 = F_13 ( V_11 -> V_12 ) ;
F_36 ( & V_11 -> V_43 ) ;
F_11 ( & V_11 -> V_50 ) ;
V_11 -> V_51 = V_52 ;
F_12 ( & V_11 -> V_53 ) ;
V_11 -> V_54 = V_55 ;
V_11 -> V_31 = V_55 ;
V_11 -> V_5 = F_37 ( L_7 ,
sizeof( struct V_3 ) , 0 , 0 , NULL ) ;
if ( ! V_11 -> V_5 ) {
F_6 ( V_8 , L_8 , V_9 ) ;
F_38 ( & V_11 -> V_49 ) ;
return - V_56 ;
}
V_6 = F_4 ( V_11 -> V_5 ) ;
if ( ! V_6 ) {
F_6 ( V_8 , L_4 , V_9 ) ;
F_38 ( & V_11 -> V_49 ) ;
return - V_56 ;
}
V_42 = F_7 ( V_11 , V_6 , V_11 -> V_12 ) ;
if ( V_42 ) {
F_6 ( V_8 , L_5 , V_9 ) ;
F_26 ( V_11 -> V_5 , V_6 ) ;
F_38 ( & V_11 -> V_49 ) ;
return - V_13 ;
}
F_27 ( & V_11 -> V_43 , V_41 ) ;
F_28 ( & V_6 -> V_15 , & V_11 -> V_53 ) ;
F_29 ( & V_11 -> V_43 , V_41 ) ;
F_19 ( & V_11 -> V_31 , V_6 ) ;
return 0 ;
}
struct V_3 * F_39 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
struct V_3 * V_6 , * V_40 ;
struct V_32 * V_33 = & V_11 -> V_31 ;
F_8 ( V_11 , NULL ) ;
F_9 ( F_10 ( V_11 ) , 0 , NULL ,
L_2 ) ;
if ( V_12 == 0 ) {
F_6 ( V_8 , L_3 ) ;
return NULL ;
}
F_40 ( & V_11 -> V_50 ) ;
V_6 = F_14 ( V_33 -> V_23 , V_12 ) ;
if ( ! V_6 ) {
F_41 ( & V_11 -> V_50 ) ;
F_6 ( V_8 , L_9 ,
V_9 ) ;
return NULL ;
}
if ( V_6 -> V_12 > V_12 ) {
V_40 = F_25 ( V_11 , V_6 , V_12 ) ;
if ( ! V_40 ) {
F_41 ( & V_11 -> V_50 ) ;
F_6 ( V_8 , L_10 ,
V_9 ) ;
return NULL ;
}
F_23 ( & V_11 -> V_54 , V_40 ) ;
F_19 ( & V_11 -> V_31 , V_6 ) ;
F_41 ( & V_11 -> V_50 ) ;
return V_40 ;
}
F_23 ( & V_11 -> V_54 , V_6 ) ;
F_41 ( & V_11 -> V_50 ) ;
return V_6 ;
}
void F_42 ( struct V_3 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_3 * V_44 , * V_57 ;
F_40 ( & V_11 -> V_50 ) ;
if ( V_6 -> V_17 & V_58 ) {
F_41 ( & V_11 -> V_50 ) ;
F_43 ( V_8 , L_11 ) ;
return;
}
if ( V_6 -> V_17 & V_59 ) {
F_44 ( V_8 , L_12 ) ;
F_45 ( V_6 ) ;
}
if ( V_6 -> V_17 & V_60 ) {
F_44 ( V_8 , L_13 ) ;
F_46 ( V_6 ) ;
}
if ( V_6 -> V_17 & V_61 || V_6 -> V_17 & V_62 ) {
F_44 ( V_8 , L_14 ) ;
F_47 ( V_6 ) ;
}
F_16 ( & V_6 -> V_24 , & V_11 -> V_54 ) ;
V_57 = F_48 ( V_6 -> V_15 . V_21 , struct V_3 , V_15 ) ;
V_44 = F_48 ( V_6 -> V_15 . V_22 , struct V_3 , V_15 ) ;
if ( V_6 -> V_15 . V_21 != & V_11 -> V_53 &&
V_57 -> V_20 == V_6 -> V_19 &&
( V_57 -> V_17 & V_37 ) == V_18 ) {
F_30 ( V_57 ) ;
V_6 = F_31 ( V_57 , V_6 ) ;
}
if ( V_6 -> V_15 . V_22 != & V_11 -> V_53 &&
V_44 -> V_19 == V_6 -> V_20 &&
( V_44 -> V_17 & V_37 ) == V_18 ) {
F_30 ( V_44 ) ;
V_6 = F_31 ( V_6 , V_44 ) ;
}
F_19 ( & V_11 -> V_31 , V_6 ) ;
F_41 ( & V_11 -> V_50 ) ;
return;
}
void F_49 ( struct V_10 * V_11 )
{
struct V_3 * V_6 ;
unsigned long V_41 ;
F_43 ( V_8 , L_15 , V_9 ) ;
F_50 ( V_11 ) ;
while ( ! F_51 ( & V_11 -> V_54 ) )
F_42 (
F_52 ( V_11 -> V_54 . V_23 ) ) ;
F_43 ( V_8 , L_16 ,
V_9 ) ;
while ( ! F_53 ( & V_11 -> V_53 ) ) {
V_6 = F_54 ( V_11 -> V_53 . V_22 ) ;
F_27 ( & V_11 -> V_43 , V_41 ) ;
F_32 ( & V_6 -> V_15 ) ;
F_29 ( & V_11 -> V_43 , V_41 ) ;
F_26 ( V_11 -> V_5 , V_6 ) ;
}
F_43 ( V_8 , L_17 , V_9 ) ;
F_55 ( V_11 -> V_5 ) ;
F_38 ( & V_11 -> V_49 ) ;
}
int F_10 ( struct V_10 * V_11 )
{
F_8 ( V_11 , - V_13 ) ;
return V_11 -> V_51 == V_52 ;
}
int F_56 ( struct V_3 * V_6 )
{
F_57 ( V_6 , 0 ) ;
return V_6 -> V_17 & V_39 ;
}
struct V_3 * F_58 (
struct V_10 * V_11 , T_1 V_63 )
{
struct V_3 * V_6 ;
F_8 ( V_11 , NULL ) ;
F_40 ( & V_11 -> V_50 ) ;
V_6 = F_17 ( & V_11 -> V_54 , V_63 ) ;
if ( ! V_6 ) {
F_41 ( & V_11 -> V_50 ) ;
F_6 ( V_8 , L_18 ,
V_9 , V_63 ) ;
return NULL ;
}
F_41 ( & V_11 -> V_50 ) ;
return V_6 ;
}
struct V_3 * F_59 (
struct V_10 * V_11 , unsigned int V_63 )
{
struct V_3 * V_6 ;
F_8 ( V_11 , NULL ) ;
F_40 ( & V_11 -> V_50 ) ;
V_6 = F_18 ( & V_11 -> V_54 , V_63 ) ;
if ( ! V_6 ) {
F_41 ( & V_11 -> V_50 ) ;
F_6 ( V_8 , L_19 ,
V_9 , V_63 ) ;
return NULL ;
}
F_41 ( & V_11 -> V_50 ) ;
return V_6 ;
}
struct V_3 * F_60 (
struct V_10 * V_11 , const void * V_63 )
{
struct V_64 * V_65 ;
struct V_3 * V_6 ;
unsigned long V_41 ;
F_8 ( V_11 , NULL ) ;
F_27 ( & V_11 -> V_43 , V_41 ) ;
F_61 (pos, &bdev->entire_bo_list) {
V_6 = F_54 ( V_65 ) ;
if ( ( V_6 -> V_17 & V_37 ) == V_18 )
continue;
if ( V_6 -> V_16 == V_63 )
goto V_66;
}
F_29 ( & V_11 -> V_43 , V_41 ) ;
return NULL ;
V_66:
F_29 ( & V_11 -> V_43 , V_41 ) ;
return V_6 ;
}
static void F_62 ( struct V_3 * V_6 ,
struct V_67 * V_68 ,
struct V_67 * V_69 ,
int V_70 )
{
int V_71 , V_42 ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ ) {
switch ( V_6 -> V_72 [ V_71 ] . type ) {
case V_73 :
if ( V_69 -> V_74
&& V_69 -> V_74 -> V_75 ) {
V_69 -> V_74 -> V_75 ( V_69 -> V_76 ,
& V_6 -> V_72 [ V_71 ] ) ;
V_77 . V_78 -- ;
}
break;
case V_79 :
case V_80 :
if ( V_68 -> V_74
&& V_68 -> V_74 -> V_81
&& V_68 -> V_74 -> V_81 ( V_68 -> V_76 ) ) {
if ( V_68 -> V_74 -> V_75 )
V_68 -> V_74 -> V_75 (
V_68 -> V_76 ,
& V_6 -> V_72 [ V_71 ] ) ;
break;
}
default:
V_42 = F_63 ( V_6 -> V_72 [ V_71 ] . V_82 , 1 ) ;
if ( V_42 )
F_6 ( V_8 ,
L_20 ,
V_42 ) ;
if ( ! V_42 ) {
F_64 ( V_6 -> V_72 [ V_71 ] . V_82 , 0 ) ;
V_77 . V_83 -- ;
}
break;
}
}
return;
}
static int F_65 ( struct V_3 * V_6 ,
int V_84 ,
bool V_85 ,
struct V_67 * V_68 ,
struct V_67 * V_69 )
{
int V_42 ;
unsigned int V_12 , V_1 , V_86 , V_87 ;
struct V_82 * V_88 ;
T_2 V_89 = V_90 | V_91 ;
int V_71 , V_92 ;
int V_93 = 0 ;
bool V_94 = false ;
bool V_95 = true ;
if ( V_84 )
V_89 |= V_96 ;
V_12 = V_6 -> V_12 ;
V_6 -> V_72 = F_66 ( sizeof( struct V_97 ) * V_12 ,
V_7 ) ;
if ( F_67 ( ! V_6 -> V_72 ) ) {
F_6 ( V_8 , L_21 ) ;
return - V_56 ;
}
V_71 = 0 ;
V_87 = 0 ;
if ( V_68 -> V_74 && V_68 -> V_74 -> V_98 ) {
V_87 = V_68 -> V_74 -> V_98 ( V_68 -> V_76 ,
V_6 -> V_72 , V_12 ,
V_85 ) ;
V_77 . V_99 -= V_87 ;
if ( V_87 == V_12 )
return 0 ;
}
V_12 -= V_87 ;
V_71 += V_87 ;
if ( V_69 -> V_74 && V_69 -> V_74 -> V_98 ) {
V_87 = V_69 -> V_74 -> V_98 ( V_69 -> V_76 ,
& V_6 -> V_72 [ V_71 ] , V_12 ,
V_85 ) ;
V_77 . V_78 += V_87 ;
if ( V_87 == V_12 )
return 0 ;
}
V_12 -= V_87 ;
V_71 += V_87 ;
while ( V_12 ) {
V_1 = F_2 ( V_12 ) ;
if ( V_95 )
V_1 = V_100 ;
else if ( V_1 > V_101 )
V_1 = V_101 ;
V_102:
if ( V_1 == V_100 ) {
V_89 &= ~ V_90 ;
V_89 |= V_103 | V_104 ;
}
V_88 = F_68 ( V_89 , V_1 ) ;
if ( F_67 ( ! V_88 ) ) {
if ( V_1 == V_100 ) {
F_6 ( V_8 ,
L_22 ,
V_9 ) ;
goto V_105;
}
V_1 = V_100 ;
V_93 ++ ;
V_94 = true ;
if ( V_93 == 2 ) {
V_95 = true ;
V_93 = 0 ;
}
goto V_102;
} else {
V_86 = F_1 ( V_1 ) ;
if ( ! V_85 ) {
V_42 = F_69 ( V_88 , V_86 ) ;
if ( V_42 ) {
F_6 ( V_8 ,
L_23
L_24 ) ;
F_64 ( V_88 , V_1 ) ;
goto V_105;
}
}
for ( V_92 = 0 ; V_92 < V_86 ; V_92 ++ ) {
V_6 -> V_72 [ V_71 ] . V_82 = V_88 + V_92 ;
V_6 -> V_72 [ V_71 ++ ] . type = V_80 ;
}
V_12 -= V_86 ;
V_77 . V_83 += V_86 ;
if ( V_94 )
V_94 = false ;
else
V_93 = 0 ;
}
}
return 0 ;
V_105:
V_87 = V_71 ;
F_62 ( V_6 , V_68 , V_69 , V_87 ) ;
F_70 ( V_6 -> V_72 ) ;
return - V_56 ;
}
static void F_71 ( struct V_3 * V_6 ,
struct V_67 * V_68 ,
struct V_67 * V_69 )
{
F_62 ( V_6 , V_68 , V_69 , V_6 -> V_12 ) ;
F_70 ( V_6 -> V_72 ) ;
}
static int F_72 ( struct V_106 * V_107 , struct V_108 * V_109 ,
unsigned long V_19 , int V_110 ,
unsigned int V_111 , struct V_82 * * V_88 ,
struct V_112 * * V_113 )
{
int V_71 , V_42 ;
unsigned long V_114 ;
if ( V_110 <= 0 )
return 0 ;
F_73 ( ! ! V_88 != ! ! ( V_111 & V_115 ) ) ;
V_114 = ( V_111 & V_116 ) ?
( V_117 | V_118 ) : ( V_119 | V_120 ) ;
V_114 &= ( V_111 & V_121 ) ?
( V_120 | V_118 ) : ( V_119 | V_117 ) ;
V_71 = 0 ;
do {
struct V_112 * V_122 ;
V_122 = F_74 ( V_109 , V_19 ) ;
if ( ! V_122 ) {
F_6 ( V_8 , L_25 ) ;
return V_71 ? : - V_123 ;
}
if ( F_75 ( V_122 ) ) {
continue;
}
do {
struct V_82 * V_82 ;
unsigned long V_124 ;
if ( F_67 ( F_76 ( V_125 ) ) ) {
F_6 ( V_8 ,
L_26 ,
V_9 ) ;
return V_71 ? V_71 : - V_126 ;
}
V_42 = F_77 ( V_122 , V_19 , & V_124 ) ;
if ( V_42 ) {
F_6 ( V_8 , L_27 ) ;
return V_71 ? : - V_123 ;
}
V_82 = F_78 ( V_124 ) ;
if ( F_79 ( V_82 ) )
return V_71 ? V_71 : F_80 ( V_82 ) ;
if ( V_88 ) {
V_88 [ V_71 ] = V_82 ;
F_81 ( V_82 ) ;
F_82 ( V_122 , V_82 , V_19 ) ;
F_83 ( V_82 ) ;
}
if ( V_113 )
V_113 [ V_71 ] = V_122 ;
V_71 ++ ;
V_19 += V_127 ;
V_110 -- ;
} while ( V_110 && V_19 < V_122 -> V_128 );
} while ( V_110 );
return V_71 ;
}
static int F_84 ( struct V_106 * V_107 , struct V_108 * V_109 ,
unsigned long V_19 , int V_110 , int V_129 , int V_130 ,
struct V_82 * * V_88 , struct V_112 * * V_113 )
{
int V_41 = V_131 ;
if ( V_88 )
V_41 |= V_115 ;
if ( V_129 )
V_41 |= V_116 ;
if ( V_130 )
V_41 |= V_121 ;
return F_72 ( V_107 , V_109 , V_19 , V_110 , V_41 , V_88 , V_113 ) ;
}
static int F_85 ( struct V_3 * V_6 ,
void * V_132 , bool V_85 )
{
int V_133 ;
int V_71 ;
struct V_112 * V_122 ;
struct V_82 * * V_88 ;
V_88 = F_66 ( sizeof( struct V_82 * ) * V_6 -> V_12 , V_7 ) ;
if ( F_67 ( ! V_88 ) ) {
F_6 ( V_8 , L_28 ) ;
return - V_56 ;
}
V_6 -> V_72 = F_66 ( sizeof( struct V_97 ) * V_6 -> V_12 ,
V_7 ) ;
if ( F_67 ( ! V_6 -> V_72 ) ) {
F_6 ( V_8 , L_29 ) ;
F_70 ( V_88 ) ;
return - V_56 ;
}
F_41 ( & V_6 -> V_14 ) ;
F_86 ( & V_125 -> V_109 -> V_134 ) ;
V_122 = F_74 ( V_125 -> V_109 , ( unsigned long ) V_132 ) ;
F_87 ( & V_125 -> V_109 -> V_134 ) ;
if ( V_122 == NULL ) {
F_6 ( V_8 , L_25 ) ;
F_70 ( V_6 -> V_72 ) ;
F_70 ( V_88 ) ;
F_40 ( & V_6 -> V_14 ) ;
return - V_123 ;
}
F_40 ( & V_6 -> V_14 ) ;
if ( V_122 -> V_114 & ( V_135 | V_136 ) ) {
V_133 = F_84 ( V_125 , V_125 -> V_109 ,
( unsigned long ) V_132 ,
( int ) ( V_6 -> V_12 ) , 1 , 0 ,
V_88 , NULL ) ;
V_6 -> V_137 = V_138 ;
} else {
F_41 ( & V_6 -> V_14 ) ;
F_86 ( & V_125 -> V_109 -> V_134 ) ;
V_133 = F_88 ( ( unsigned long ) V_132 ,
( int ) ( V_6 -> V_12 ) , 1 , V_88 , NULL ) ;
F_87 ( & V_125 -> V_109 -> V_134 ) ;
F_40 ( & V_6 -> V_14 ) ;
V_6 -> V_137 = V_139 ;
}
if ( V_133 != V_6 -> V_12 ) {
F_6 ( V_8 ,
L_30
L_31 ,
V_6 -> V_12 , V_133 ) ;
goto V_140;
}
for ( V_71 = 0 ; V_71 < V_6 -> V_12 ; V_71 ++ ) {
V_6 -> V_72 [ V_71 ] . V_82 = V_88 [ V_71 ] ;
V_6 -> V_72 [ V_71 ] . type = V_80 ;
}
V_77 . V_141 += V_6 -> V_12 ;
F_70 ( V_88 ) ;
return 0 ;
V_140:
for ( V_71 = 0 ; V_71 < V_133 ; V_71 ++ )
F_89 ( V_88 [ V_71 ] ) ;
F_70 ( V_88 ) ;
F_70 ( V_6 -> V_72 ) ;
return - V_56 ;
}
static void F_90 ( struct V_3 * V_6 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_6 -> V_12 ; V_71 ++ )
F_89 ( V_6 -> V_72 [ V_71 ] . V_82 ) ;
V_77 . V_141 -= V_6 -> V_12 ;
F_70 ( V_6 -> V_72 ) ;
}
int F_91 ( struct V_3 * V_6 ,
enum V_142 type , int V_84 ,
void * V_132 , bool V_85 )
{
int V_42 = - V_13 ;
F_57 ( V_6 , - V_13 ) ;
F_40 ( & V_6 -> V_14 ) ;
F_92 ( V_6 , V_60 , V_143 ) ;
if ( type == V_144 ) {
V_42 = F_65 ( V_6 , V_84 ,
V_85 , & V_145 , & V_146 ) ;
} else if ( type == V_147 ) {
V_42 = F_85 ( V_6 , V_132 , V_85 ) ;
} else {
F_6 ( V_8 , L_32 ) ;
V_42 = - V_13 ;
}
if ( V_42 )
goto V_148;
V_6 -> type = type ;
V_6 -> V_17 |= V_60 ;
F_41 ( & V_6 -> V_14 ) ;
return 0 ;
V_148:
F_41 ( & V_6 -> V_14 ) ;
F_6 ( V_8 , L_33 ) ;
return V_42 ;
V_143:
F_41 ( & V_6 -> V_14 ) ;
F_6 ( V_8 ,
L_34 ) ;
return - V_13 ;
}
void F_46 ( struct V_3 * V_6 )
{
F_93 ( V_6 ) ;
F_40 ( & V_6 -> V_14 ) ;
F_94 ( V_6 , V_60 , V_149 ) ;
V_6 -> V_17 &= ( ~ V_60 ) ;
if ( V_6 -> type == V_144 )
F_71 ( V_6 , & V_145 , & V_146 ) ;
else if ( V_6 -> type == V_147 )
F_90 ( V_6 ) ;
else
F_6 ( V_8 , L_32 ) ;
F_41 ( & V_6 -> V_14 ) ;
return;
V_149:
F_41 ( & V_6 -> V_14 ) ;
F_6 ( V_8 ,
L_35 ) ;
}
int F_95 ( struct V_3 * V_6 )
{
int V_42 ;
F_57 ( V_6 , 0 ) ;
V_42 = V_6 -> V_17 & V_60 ;
return V_42 ;
}
int F_96 ( struct V_3 * V_6 ,
struct V_97 * * V_72 , int * V_12 )
{
F_57 ( V_6 , - V_13 ) ;
F_40 ( & V_6 -> V_14 ) ;
F_94 ( V_6 , V_60 , V_143 ) ;
* V_72 = V_6 -> V_72 ;
* V_12 = V_6 -> V_12 ;
F_41 ( & V_6 -> V_14 ) ;
return 0 ;
V_143:
F_6 ( V_8 ,
L_35 ) ;
F_41 ( & V_6 -> V_14 ) ;
return - V_13 ;
}
int F_97 ( struct V_3 * V_6 )
{
int V_42 ;
unsigned int V_150 ;
struct V_10 * V_11 ;
unsigned int V_71 ;
F_57 ( V_6 , - V_13 ) ;
F_40 ( & V_6 -> V_14 ) ;
F_94 ( V_6 ,
V_60 | V_39 ,
V_151 ) ;
F_92 ( V_6 , V_59 , V_149 ) ;
V_11 = V_6 -> V_11 ;
V_150 = V_6 -> V_19 ;
for ( V_71 = 0 ; V_71 < V_6 -> V_12 ; V_71 ++ ) {
V_42 =
F_98 ( & V_11 -> V_49 , V_150 ,
F_99 ( V_6 -> V_72 [ V_71 ] . V_82 ) , 1 ) ;
if ( V_42 )
goto V_152;
V_150 += ( 1 << V_153 ) ;
}
if ( V_6 -> V_19 != 0x0 )
F_100 ( & V_11 -> V_49 , V_6 -> V_19 ,
( V_6 -> V_12 << V_153 ) ) ;
V_6 -> V_17 |= V_59 ;
F_41 ( & V_6 -> V_14 ) ;
return 0 ;
V_152:
V_150 = V_6 -> V_19 ;
for ( ; V_71 > 0 ; V_71 -- ) {
F_101 ( & V_11 -> V_49 , V_150 , 1 ) ;
V_150 += F_13 ( 1 ) ;
}
F_41 ( & V_6 -> V_14 ) ;
F_6 ( V_8 ,
L_36 ) ;
return V_42 ;
V_149:
F_41 ( & V_6 -> V_14 ) ;
F_6 ( V_8 , L_37 ) ;
return - V_13 ;
V_151:
F_41 ( & V_6 -> V_14 ) ;
F_6 ( V_8 ,
L_38 ) ;
return - V_13 ;
}
void F_45 ( struct V_3 * V_6 )
{
unsigned int V_150 ;
struct V_10 * V_11 ;
unsigned int V_71 ;
F_93 ( V_6 ) ;
F_40 ( & V_6 -> V_14 ) ;
F_94 ( V_6 ,
V_60 |
V_39 |
V_59 , V_143 ) ;
V_11 = V_6 -> V_11 ;
V_150 = V_6 -> V_19 ;
for ( V_71 = 0 ; V_71 < V_6 -> V_12 ; V_71 ++ ) {
F_101 ( & V_11 -> V_49 , V_150 , 1 ) ;
V_150 += F_13 ( 1 ) ;
}
F_100 ( & V_11 -> V_49 , V_6 -> V_19 ,
( V_6 -> V_12 << V_153 ) ) ;
V_6 -> V_17 &= ( ~ V_59 ) ;
F_41 ( & V_6 -> V_14 ) ;
return;
V_143:
F_41 ( & V_6 -> V_14 ) ;
F_6 ( V_8 ,
L_39 ) ;
}
int F_102 ( struct V_3 * V_6 )
{
int V_42 ;
F_57 ( V_6 , 0 ) ;
F_40 ( & V_6 -> V_14 ) ;
V_42 = V_6 -> V_17 & V_59 ;
F_41 ( & V_6 -> V_14 ) ;
return V_42 ;
}
void * F_103 ( struct V_3 * V_6 , bool V_85 )
{
struct V_82 * * V_88 ;
int V_71 ;
F_57 ( V_6 , NULL ) ;
F_40 ( & V_6 -> V_14 ) ;
if ( ( ( V_6 -> V_17 & V_61 ) && ! V_85 ) ||
( ( V_6 -> V_17 & V_62 ) && V_85 ) ) {
F_41 ( & V_6 -> V_14 ) ;
return V_6 -> V_16 ;
}
if ( V_6 -> V_17 & V_61 || V_6 -> V_17 & V_62 ) {
F_104 ( V_6 -> V_16 ) ;
V_6 -> V_16 = NULL ;
V_6 -> V_17 &= ~ ( V_61 | V_62 ) ;
}
V_88 = F_66 ( sizeof( * V_88 ) * V_6 -> V_12 , V_7 ) ;
if ( F_67 ( ! V_88 ) ) {
F_41 ( & V_6 -> V_14 ) ;
F_6 ( V_8 , L_28 ) ;
return NULL ;
}
for ( V_71 = 0 ; V_71 < V_6 -> V_12 ; V_71 ++ )
V_88 [ V_71 ] = V_6 -> V_72 [ V_71 ] . V_82 ;
V_6 -> V_16 = F_105 ( V_88 , V_6 -> V_12 , V_154 ,
V_85 ? V_155 : V_156 ) ;
if ( F_67 ( ! V_6 -> V_16 ) ) {
F_70 ( V_88 ) ;
F_41 ( & V_6 -> V_14 ) ;
F_6 ( V_8 , L_40 ) ;
return NULL ;
}
V_6 -> V_17 |= ( V_85 ? V_62 : V_61 ) ;
F_70 ( V_88 ) ;
F_41 ( & V_6 -> V_14 ) ;
return V_6 -> V_16 ;
}
void F_106 ( struct V_3 * V_6 )
{
F_93 ( V_6 ) ;
F_40 ( & V_6 -> V_14 ) ;
if ( ! ( V_6 -> V_17 & V_62 ) || ! V_6 -> V_16 ) {
F_41 ( & V_6 -> V_14 ) ;
return;
}
F_107 ( V_6 -> V_16 , V_6 -> V_12 * V_127 ) ;
F_41 ( & V_6 -> V_14 ) ;
}
void F_47 ( struct V_3 * V_6 )
{
F_93 ( V_6 ) ;
F_40 ( & V_6 -> V_14 ) ;
if ( V_6 -> V_17 & V_61 || V_6 -> V_17 & V_62 ) {
F_104 ( V_6 -> V_16 ) ;
V_6 -> V_16 = NULL ;
V_6 -> V_17 &= ~ ( V_61 | V_62 ) ;
}
F_41 ( & V_6 -> V_14 ) ;
return;
}
void F_108 ( struct V_3 * V_6 )
{
F_93 ( V_6 ) ;
F_109 ( & V_6 -> V_38 ) ;
}
static void F_110 ( struct V_38 * V_38 )
{
if ( ! V_38 )
return;
F_42 ( F_111 ( V_38 ) ) ;
}
void F_112 ( struct V_3 * V_6 )
{
F_93 ( V_6 ) ;
F_113 ( & V_6 -> V_38 , F_110 ) ;
}
static void F_114 ( struct V_112 * V_122 )
{
struct V_3 * V_6 =
(struct V_3 * ) V_122 -> V_157 ;
F_93 ( V_6 ) ;
F_108 ( V_6 ) ;
F_40 ( & V_6 -> V_14 ) ;
V_6 -> V_17 |= V_58 ;
V_6 -> V_158 ++ ;
F_41 ( & V_6 -> V_14 ) ;
}
static void F_115 ( struct V_112 * V_122 )
{
struct V_3 * V_6 =
(struct V_3 * ) V_122 -> V_157 ;
F_93 ( V_6 ) ;
F_112 ( V_6 ) ;
F_40 ( & V_6 -> V_14 ) ;
V_6 -> V_158 -- ;
if ( ! V_6 -> V_158 ) {
V_6 -> V_17 &= ( ~ V_58 ) ;
V_122 -> V_157 = NULL ;
}
F_41 ( & V_6 -> V_14 ) ;
}
int F_116 ( struct V_112 * V_122 , struct V_3 * V_6 )
{
unsigned int V_19 , V_20 ;
unsigned int V_150 ;
unsigned int V_12 , V_71 ;
unsigned int V_124 ;
F_57 ( V_6 , - V_13 ) ;
F_94 ( V_6 , V_60 , V_143 ) ;
V_12 = V_6 -> V_12 ;
V_19 = V_122 -> V_159 ;
V_20 = V_122 -> V_128 ;
if ( ( V_19 + F_13 ( V_12 ) ) != V_20 ) {
F_44 ( V_8 ,
L_41
L_42 ) ;
return - V_13 ;
}
V_150 = V_122 -> V_159 ;
for ( V_71 = 0 ; V_71 < V_12 ; V_71 ++ ) {
V_124 = F_117 ( V_6 -> V_72 [ V_71 ] . V_82 ) ;
if ( F_118 ( V_122 , V_150 , V_124 , V_127 , V_160 ) ) {
F_44 ( V_8 ,
L_43
L_44
L_45 , V_150 , V_124 , 1 ) ;
return - V_13 ;
}
V_150 += V_127 ;
}
V_122 -> V_157 = V_6 ;
V_122 -> V_161 = & V_162 ;
V_122 -> V_114 |= V_135 | V_163 | V_164 ;
F_114 ( V_122 ) ;
return 0 ;
V_143:
F_6 ( V_8 , L_46 ) ;
return - V_13 ;
}
