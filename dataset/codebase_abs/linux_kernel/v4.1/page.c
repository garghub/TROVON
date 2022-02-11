static struct V_1 *
F_1 ( struct V_2 * V_2 , unsigned long V_3 , T_1 V_4 ,
int V_5 , unsigned long V_6 )
{
unsigned long V_7 ;
struct V_1 * V_8 ;
if ( ! F_2 ( V_2 ) )
F_3 ( V_2 , 1 << V_5 , V_6 ) ;
V_7 = ( unsigned long ) V_4 << ( V_9 - V_5 ) ;
V_8 = F_4 ( V_2 , V_3 - V_7 ) ;
F_5 ( V_8 ) ;
F_6 ( V_8 ) ;
return V_8 ;
}
struct V_1 * F_7 ( struct V_10 * V_10 ,
struct V_11 * V_12 ,
unsigned long V_13 ,
unsigned long V_6 )
{
int V_5 = V_10 -> V_14 ;
T_1 V_4 = V_13 >> ( V_9 - V_5 ) ;
struct V_2 * V_2 ;
struct V_1 * V_8 ;
V_2 = F_8 ( V_12 , V_4 ) ;
if ( F_9 ( ! V_2 ) )
return NULL ;
V_8 = F_1 ( V_2 , V_13 , V_4 , V_5 , V_6 ) ;
if ( F_9 ( ! V_8 ) ) {
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
return NULL ;
}
return V_8 ;
}
void F_12 ( struct V_1 * V_8 )
{
struct V_2 * V_2 = V_8 -> V_15 ;
const unsigned long V_16 =
( 1 << V_17 | 1 << V_18 | 1 << V_19 |
1 << V_20 | 1 << V_21 |
1 << V_22 | 1 << V_23 ) ;
F_13 ( V_8 ) ;
F_14 ( & V_8 -> V_6 , V_16 , 0 ) ;
if ( F_15 ( V_2 ) )
F_16 ( V_2 ) ;
V_8 -> V_24 = - 1 ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_8 ) ;
F_20 ( V_8 ) ;
}
void F_21 ( struct V_1 * V_25 , struct V_1 * V_26 )
{
void * V_27 , * V_28 ;
unsigned long V_29 ;
struct V_2 * V_30 = V_26 -> V_15 , * V_31 = V_25 -> V_15 ;
struct V_1 * V_8 ;
V_27 = F_22 ( V_30 ) ;
V_28 = F_22 ( V_31 ) ;
memcpy ( V_28 + F_23 ( V_25 ) , V_27 + F_23 ( V_26 ) , V_26 -> V_32 ) ;
F_24 ( V_28 ) ;
F_24 ( V_27 ) ;
V_25 -> V_6 = V_26 -> V_6 & V_33 ;
V_25 -> V_24 = V_26 -> V_24 ;
V_25 -> V_34 = V_26 -> V_34 ;
V_8 = V_25 ;
V_29 = V_26 -> V_6 & ( ( 1UL << V_17 ) | ( 1UL << V_19 ) ) ;
while ( ( V_8 = V_8 -> V_35 ) != V_25 ) {
F_13 ( V_8 ) ;
V_29 &= V_8 -> V_6 ;
F_19 ( V_8 ) ;
}
if ( V_29 & ( 1UL << V_17 ) )
F_25 ( V_31 ) ;
else
F_17 ( V_31 ) ;
if ( V_29 & ( 1UL << V_19 ) )
F_26 ( V_31 ) ;
else
F_18 ( V_31 ) ;
}
int F_15 ( struct V_2 * V_2 )
{
struct V_1 * V_8 , * V_36 ;
V_8 = V_36 = F_27 ( V_2 ) ;
do {
if ( F_28 ( V_8 ) )
return 0 ;
V_8 = V_8 -> V_35 ;
} while ( V_8 != V_36 );
return 1 ;
}
void F_29 ( struct V_2 * V_2 )
{
struct V_11 * V_37 ;
unsigned long V_38 ;
if ( F_9 ( ! V_2 ) ) {
F_30 ( V_39 L_1 ) ;
return;
}
V_37 = V_2 -> V_12 ;
V_38 = V_37 ? V_37 -> V_40 -> V_41 : 0 ;
F_30 ( V_39 L_2
L_3 ,
V_2 , F_31 ( & V_2 -> V_42 ) ,
( unsigned long long ) V_2 -> V_4 , V_2 -> V_43 , V_37 , V_38 ) ;
if ( F_2 ( V_2 ) ) {
struct V_1 * V_8 , * V_36 ;
int V_44 = 0 ;
V_8 = V_36 = F_27 ( V_2 ) ;
do {
F_30 ( V_39
L_4 ,
V_44 ++ , V_8 , F_31 ( & V_8 -> V_45 ) ,
( unsigned long long ) V_8 -> V_24 , V_8 -> V_6 ) ;
V_8 = V_8 -> V_35 ;
} while ( V_8 != V_36 );
}
}
static void F_32 ( struct V_2 * V_46 , struct V_2 * V_47 , int V_48 )
{
struct V_1 * V_25 , * V_49 , * V_26 , * V_50 ;
unsigned long V_51 = V_33 ;
F_33 ( F_34 ( V_46 ) ) ;
V_26 = V_50 = F_27 ( V_47 ) ;
if ( ! F_2 ( V_46 ) )
F_3 ( V_46 , V_26 -> V_32 , 0 ) ;
if ( V_48 )
V_51 |= ( 1UL << V_18 ) ;
V_25 = V_49 = F_27 ( V_46 ) ;
do {
F_13 ( V_26 ) ;
F_13 ( V_25 ) ;
V_25 -> V_6 = V_26 -> V_6 & V_51 ;
V_25 -> V_24 = V_26 -> V_24 ;
V_25 -> V_34 = V_26 -> V_34 ;
V_26 = V_26 -> V_35 ;
V_25 = V_25 -> V_35 ;
} while ( V_25 != V_49 );
F_35 ( V_46 , V_47 ) ;
if ( F_36 ( V_47 ) && ! F_36 ( V_46 ) )
F_25 ( V_46 ) ;
else if ( ! F_36 ( V_47 ) && F_36 ( V_46 ) )
F_17 ( V_46 ) ;
if ( F_37 ( V_47 ) && ! F_37 ( V_46 ) )
F_26 ( V_46 ) ;
else if ( ! F_37 ( V_47 ) && F_37 ( V_46 ) )
F_18 ( V_46 ) ;
do {
F_19 ( V_26 ) ;
F_19 ( V_25 ) ;
V_26 = V_26 -> V_35 ;
V_25 = V_25 -> V_35 ;
} while ( V_25 != V_49 );
}
int F_38 ( struct V_11 * V_52 ,
struct V_11 * V_53 )
{
struct V_54 V_55 ;
unsigned int V_44 ;
T_1 V_4 = 0 ;
int V_56 = 0 ;
F_39 ( & V_55 , 0 ) ;
V_57:
if ( ! F_40 ( & V_55 , V_53 , & V_4 , V_58 ,
V_59 ) )
return 0 ;
for ( V_44 = 0 ; V_44 < F_41 ( & V_55 ) ; V_44 ++ ) {
struct V_2 * V_2 = V_55 . V_60 [ V_44 ] , * V_31 ;
F_42 ( V_2 ) ;
if ( F_9 ( ! F_43 ( V_2 ) ) )
F_44 ( V_2 , L_5 ) ;
V_31 = F_8 ( V_52 , V_2 -> V_4 ) ;
if ( F_9 ( ! V_31 ) ) {
V_56 = - V_61 ;
F_10 ( V_2 ) ;
break;
}
if ( F_9 ( ! F_2 ( V_2 ) ) )
F_44 ( V_2 ,
L_6 ) ;
F_32 ( V_31 , V_2 , 1 ) ;
F_45 ( V_31 ) ;
F_10 ( V_31 ) ;
F_11 ( V_31 ) ;
F_10 ( V_2 ) ;
}
F_46 ( & V_55 ) ;
F_47 () ;
if ( F_48 ( ! V_56 ) )
goto V_57;
return V_56 ;
}
void F_49 ( struct V_11 * V_52 ,
struct V_11 * V_53 )
{
struct V_54 V_55 ;
unsigned int V_44 , V_62 ;
T_1 V_4 = 0 ;
int V_56 ;
F_39 ( & V_55 , 0 ) ;
V_57:
V_62 = F_50 ( & V_55 , V_53 , V_4 , V_59 ) ;
if ( ! V_62 )
return;
V_4 = V_55 . V_60 [ V_62 - 1 ] -> V_4 + 1 ;
for ( V_44 = 0 ; V_44 < F_41 ( & V_55 ) ; V_44 ++ ) {
struct V_2 * V_2 = V_55 . V_60 [ V_44 ] , * V_31 ;
T_1 V_63 = V_2 -> V_4 ;
F_42 ( V_2 ) ;
V_31 = F_51 ( V_52 , V_63 ) ;
if ( V_31 ) {
F_52 ( F_43 ( V_31 ) ) ;
F_32 ( V_31 , V_2 , 0 ) ;
F_10 ( V_31 ) ;
F_11 ( V_31 ) ;
} else {
struct V_2 * V_64 ;
F_53 ( & V_53 -> V_65 ) ;
V_64 = F_54 ( & V_53 -> V_66 , V_63 ) ;
F_52 ( V_64 != V_2 ) ;
V_53 -> V_67 -- ;
F_55 ( & V_53 -> V_65 ) ;
F_53 ( & V_52 -> V_65 ) ;
V_56 = F_56 ( & V_52 -> V_66 , V_63 , V_2 ) ;
if ( F_9 ( V_56 < 0 ) ) {
F_52 ( V_56 == - V_68 ) ;
V_2 -> V_12 = NULL ;
F_11 ( V_2 ) ;
} else {
V_2 -> V_12 = V_52 ;
V_52 -> V_67 ++ ;
if ( F_43 ( V_2 ) )
F_57 ( & V_52 -> V_66 ,
V_63 ,
V_58 ) ;
}
F_55 ( & V_52 -> V_65 ) ;
}
F_10 ( V_2 ) ;
}
F_46 ( & V_55 ) ;
F_47 () ;
goto V_57;
}
void F_58 ( struct V_11 * V_12 , bool V_69 )
{
struct V_54 V_55 ;
unsigned int V_44 ;
T_1 V_4 = 0 ;
F_39 ( & V_55 , 0 ) ;
while ( F_40 ( & V_55 , V_12 , & V_4 , V_58 ,
V_59 ) ) {
for ( V_44 = 0 ; V_44 < F_41 ( & V_55 ) ; V_44 ++ ) {
struct V_2 * V_2 = V_55 . V_60 [ V_44 ] ;
F_42 ( V_2 ) ;
F_59 ( V_2 , V_69 ) ;
F_10 ( V_2 ) ;
}
F_46 ( & V_55 ) ;
F_47 () ;
}
}
void F_59 ( struct V_2 * V_2 , bool V_69 )
{
struct V_10 * V_10 = V_2 -> V_12 -> V_40 ;
struct V_70 * V_71 = V_10 -> V_72 ;
F_33 ( ! F_60 ( V_2 ) ) ;
if ( ! V_69 ) {
F_61 ( V_71 , V_73 ,
L_7 ,
F_62 ( V_2 ) , V_10 -> V_41 ) ;
}
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
if ( F_2 ( V_2 ) ) {
struct V_1 * V_8 , * V_36 ;
const unsigned long V_16 =
( 1 << V_17 | 1 << V_18 | 1 << V_19 |
1 << V_20 | 1 << V_21 |
1 << V_22 | 1 << V_23 ) ;
V_8 = V_36 = F_27 ( V_2 ) ;
do {
F_13 ( V_8 ) ;
if ( ! V_69 ) {
F_61 ( V_71 , V_73 ,
L_8 ,
( V_74 ) V_8 -> V_24 , V_8 -> V_32 ) ;
}
F_14 ( & V_8 -> V_6 , V_16 , 0 ) ;
F_19 ( V_8 ) ;
} while ( V_8 = V_8 -> V_35 , V_8 != V_36 );
}
F_16 ( V_2 ) ;
}
unsigned F_63 ( struct V_2 * V_2 ,
unsigned V_75 , unsigned V_76 )
{
unsigned V_77 , V_78 ;
struct V_1 * V_8 , * V_36 ;
unsigned V_79 = 0 ;
for ( V_8 = V_36 = F_27 ( V_2 ) , V_77 = 0 ;
V_8 != V_36 || ! V_77 ;
V_77 = V_78 , V_8 = V_8 -> V_35 ) {
V_78 = V_77 + V_8 -> V_32 ;
if ( V_78 > V_75 && V_77 < V_76 && ! F_28 ( V_8 ) )
V_79 ++ ;
}
return V_79 ;
}
void F_64 ( struct V_11 * V_12 , struct V_10 * V_10 )
{
V_12 -> V_40 = V_10 ;
V_12 -> V_43 = 0 ;
F_65 ( V_12 , V_80 ) ;
V_12 -> V_81 = NULL ;
V_12 -> V_82 = & V_83 ;
}
int F_16 ( struct V_2 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
if ( V_12 ) {
F_53 ( & V_12 -> V_65 ) ;
if ( F_66 ( V_84 , & V_2 -> V_43 ) ) {
F_67 ( & V_12 -> V_66 ,
F_68 ( V_2 ) ,
V_58 ) ;
F_55 ( & V_12 -> V_65 ) ;
return F_69 ( V_2 ) ;
}
F_55 ( & V_12 -> V_65 ) ;
return 0 ;
}
return F_70 ( V_2 ) ;
}
unsigned long F_71 ( struct V_10 * V_10 ,
T_2 V_85 ,
T_2 * V_13 )
{
unsigned int V_44 ;
T_1 V_4 ;
unsigned int V_86 ;
unsigned long V_87 = 0 ;
T_2 V_88 ;
struct V_54 V_55 ;
struct V_2 * V_2 ;
if ( V_10 -> V_89 -> V_67 == 0 )
return 0 ;
V_4 = V_85 >> ( V_9 - V_10 -> V_14 ) ;
V_86 = 1U << ( V_9 - V_10 -> V_14 ) ;
F_39 ( & V_55 , 0 ) ;
V_57:
V_55 . V_90 = F_72 ( V_10 -> V_89 , V_4 , V_59 ,
V_55 . V_60 ) ;
if ( V_55 . V_90 == 0 )
return V_87 ;
if ( V_87 > 0 && V_55 . V_60 [ 0 ] -> V_4 > V_4 )
goto V_91;
V_88 = V_55 . V_60 [ 0 ] -> V_4 << ( V_9 - V_10 -> V_14 ) ;
V_44 = 0 ;
do {
V_2 = V_55 . V_60 [ V_44 ] ;
F_42 ( V_2 ) ;
if ( F_2 ( V_2 ) ) {
struct V_1 * V_8 , * V_36 ;
V_8 = V_36 = F_27 ( V_2 ) ;
do {
if ( V_88 < V_85 )
continue;
if ( F_73 ( V_8 ) ) {
if ( V_87 == 0 )
* V_13 = V_88 ;
V_87 ++ ;
} else if ( V_87 > 0 ) {
goto V_92;
}
} while ( ++ V_88 , V_8 = V_8 -> V_35 , V_8 != V_36 );
} else {
if ( V_87 > 0 )
goto V_92;
V_88 += V_86 ;
}
F_10 ( V_2 ) ;
} while ( ++ V_44 < F_41 ( & V_55 ) );
V_4 = V_2 -> V_4 + 1 ;
F_46 ( & V_55 ) ;
F_47 () ;
goto V_57;
V_92:
F_10 ( V_2 ) ;
V_91:
F_46 ( & V_55 ) ;
return V_87 ;
}
