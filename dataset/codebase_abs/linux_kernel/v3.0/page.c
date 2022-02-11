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
F_13 ( V_8 ) ;
F_14 ( V_8 ) ;
F_15 ( V_8 ) ;
F_16 ( V_8 ) ;
F_17 ( V_8 ) ;
if ( F_18 ( V_2 ) )
F_19 ( V_2 ) ;
F_20 ( V_8 ) ;
F_21 ( V_8 ) ;
V_8 -> V_16 = - 1 ;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_8 ) ;
F_25 ( V_8 ) ;
}
void F_26 ( struct V_1 * V_17 , struct V_1 * V_18 )
{
void * V_19 , * V_20 ;
unsigned long V_21 ;
struct V_2 * V_22 = V_18 -> V_15 , * V_23 = V_17 -> V_15 ;
struct V_1 * V_8 ;
V_19 = F_27 ( V_22 , V_24 ) ;
V_20 = F_27 ( V_23 , V_25 ) ;
memcpy ( V_20 + F_28 ( V_17 ) , V_19 + F_28 ( V_18 ) , V_18 -> V_26 ) ;
F_29 ( V_20 , V_25 ) ;
F_29 ( V_19 , V_24 ) ;
V_17 -> V_6 = V_18 -> V_6 & V_27 ;
V_17 -> V_16 = V_18 -> V_16 ;
V_17 -> V_28 = V_18 -> V_28 ;
V_8 = V_17 ;
V_21 = V_18 -> V_6 & ( ( 1UL << V_29 ) | ( 1UL << V_30 ) ) ;
while ( ( V_8 = V_8 -> V_31 ) != V_17 ) {
F_13 ( V_8 ) ;
V_21 &= V_8 -> V_6 ;
F_24 ( V_8 ) ;
}
if ( V_21 & ( 1UL << V_29 ) )
F_30 ( V_23 ) ;
else
F_22 ( V_23 ) ;
if ( V_21 & ( 1UL << V_30 ) )
F_31 ( V_23 ) ;
else
F_23 ( V_23 ) ;
}
int F_18 ( struct V_2 * V_2 )
{
struct V_1 * V_8 , * V_32 ;
V_8 = V_32 = F_32 ( V_2 ) ;
do {
if ( F_33 ( V_8 ) )
return 0 ;
V_8 = V_8 -> V_31 ;
} while ( V_8 != V_32 );
return 1 ;
}
void F_34 ( struct V_2 * V_2 )
{
struct V_11 * V_33 ;
unsigned long V_34 ;
if ( F_9 ( ! V_2 ) ) {
F_35 ( V_35 L_1 ) ;
return;
}
V_33 = V_2 -> V_12 ;
V_34 = V_33 ? V_33 -> V_36 -> V_37 : 0 ;
F_35 ( V_35 L_2
L_3 ,
V_2 , F_36 ( & V_2 -> V_38 ) ,
( unsigned long long ) V_2 -> V_4 , V_2 -> V_39 , V_33 , V_34 ) ;
if ( F_2 ( V_2 ) ) {
struct V_1 * V_8 , * V_32 ;
int V_40 = 0 ;
V_8 = V_32 = F_32 ( V_2 ) ;
do {
F_35 ( V_35
L_4 ,
V_40 ++ , V_8 , F_36 ( & V_8 -> V_41 ) ,
( unsigned long long ) V_8 -> V_16 , V_8 -> V_6 ) ;
V_8 = V_8 -> V_31 ;
} while ( V_8 != V_32 );
}
}
static void F_37 ( struct V_2 * V_42 , struct V_2 * V_43 , int V_44 )
{
struct V_1 * V_17 , * V_45 , * V_18 , * V_46 ;
unsigned long V_47 = V_27 ;
F_38 ( F_39 ( V_42 ) ) ;
V_18 = V_46 = F_32 ( V_43 ) ;
if ( ! F_2 ( V_42 ) )
F_3 ( V_42 , V_18 -> V_26 , 0 ) ;
if ( V_44 )
V_47 |= ( 1UL << V_48 ) ;
V_17 = V_45 = F_32 ( V_42 ) ;
do {
F_13 ( V_18 ) ;
F_13 ( V_17 ) ;
V_17 -> V_6 = V_18 -> V_6 & V_47 ;
V_17 -> V_16 = V_18 -> V_16 ;
V_17 -> V_28 = V_18 -> V_28 ;
V_18 = V_18 -> V_31 ;
V_17 = V_17 -> V_31 ;
} while ( V_17 != V_45 );
F_40 ( V_42 , V_43 ) ;
if ( F_41 ( V_43 ) && ! F_41 ( V_42 ) )
F_30 ( V_42 ) ;
else if ( ! F_41 ( V_43 ) && F_41 ( V_42 ) )
F_22 ( V_42 ) ;
if ( F_42 ( V_43 ) && ! F_42 ( V_42 ) )
F_31 ( V_42 ) ;
else if ( ! F_42 ( V_43 ) && F_42 ( V_42 ) )
F_23 ( V_42 ) ;
do {
F_24 ( V_18 ) ;
F_24 ( V_17 ) ;
V_18 = V_18 -> V_31 ;
V_17 = V_17 -> V_31 ;
} while ( V_17 != V_45 );
}
int F_43 ( struct V_11 * V_49 ,
struct V_11 * V_50 )
{
struct V_51 V_52 ;
unsigned int V_40 ;
T_1 V_4 = 0 ;
int V_53 = 0 ;
F_44 ( & V_52 , 0 ) ;
V_54:
if ( ! F_45 ( & V_52 , V_50 , & V_4 , V_55 ,
V_56 ) )
return 0 ;
for ( V_40 = 0 ; V_40 < F_46 ( & V_52 ) ; V_40 ++ ) {
struct V_2 * V_2 = V_52 . V_57 [ V_40 ] , * V_23 ;
F_47 ( V_2 ) ;
if ( F_9 ( ! F_48 ( V_2 ) ) )
F_49 ( V_2 , L_5 ) ;
V_23 = F_8 ( V_49 , V_2 -> V_4 ) ;
if ( F_9 ( ! V_23 ) ) {
V_53 = - V_58 ;
F_10 ( V_2 ) ;
break;
}
if ( F_9 ( ! F_2 ( V_2 ) ) )
F_49 ( V_2 ,
L_6 ) ;
F_37 ( V_23 , V_2 , 1 ) ;
F_50 ( V_23 ) ;
F_10 ( V_23 ) ;
F_11 ( V_23 ) ;
F_10 ( V_2 ) ;
}
F_51 ( & V_52 ) ;
F_52 () ;
if ( F_53 ( ! V_53 ) )
goto V_54;
return V_53 ;
}
void F_54 ( struct V_11 * V_49 ,
struct V_11 * V_50 )
{
struct V_51 V_52 ;
unsigned int V_40 , V_59 ;
T_1 V_4 = 0 ;
int V_53 ;
F_44 ( & V_52 , 0 ) ;
V_54:
V_59 = F_55 ( & V_52 , V_50 , V_4 , V_56 ) ;
if ( ! V_59 )
return;
V_4 = V_52 . V_57 [ V_59 - 1 ] -> V_4 + 1 ;
for ( V_40 = 0 ; V_40 < F_46 ( & V_52 ) ; V_40 ++ ) {
struct V_2 * V_2 = V_52 . V_57 [ V_40 ] , * V_23 ;
T_1 V_60 = V_2 -> V_4 ;
F_47 ( V_2 ) ;
V_23 = F_56 ( V_49 , V_60 ) ;
if ( V_23 ) {
F_57 ( F_48 ( V_23 ) ) ;
F_37 ( V_23 , V_2 , 0 ) ;
F_10 ( V_23 ) ;
F_11 ( V_23 ) ;
} else {
struct V_2 * V_61 ;
F_58 ( & V_50 -> V_62 ) ;
V_61 = F_59 ( & V_50 -> V_63 , V_60 ) ;
F_57 ( V_61 != V_2 ) ;
V_50 -> V_64 -- ;
F_60 ( & V_50 -> V_62 ) ;
F_58 ( & V_49 -> V_62 ) ;
V_53 = F_61 ( & V_49 -> V_63 , V_60 , V_2 ) ;
if ( F_9 ( V_53 < 0 ) ) {
F_57 ( V_53 == - V_65 ) ;
V_2 -> V_12 = NULL ;
F_11 ( V_2 ) ;
} else {
V_2 -> V_12 = V_49 ;
V_49 -> V_64 ++ ;
if ( F_48 ( V_2 ) )
F_62 ( & V_49 -> V_63 ,
V_60 ,
V_55 ) ;
}
F_60 ( & V_49 -> V_62 ) ;
}
F_10 ( V_2 ) ;
}
F_51 ( & V_52 ) ;
F_52 () ;
goto V_54;
}
void F_63 ( struct V_11 * V_12 )
{
struct V_51 V_52 ;
unsigned int V_40 ;
T_1 V_4 = 0 ;
F_44 ( & V_52 , 0 ) ;
while ( F_45 ( & V_52 , V_12 , & V_4 , V_55 ,
V_56 ) ) {
for ( V_40 = 0 ; V_40 < F_46 ( & V_52 ) ; V_40 ++ ) {
struct V_2 * V_2 = V_52 . V_57 [ V_40 ] ;
struct V_1 * V_8 , * V_32 ;
F_47 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
V_8 = V_32 = F_32 ( V_2 ) ;
do {
F_13 ( V_8 ) ;
F_17 ( V_8 ) ;
F_14 ( V_8 ) ;
F_15 ( V_8 ) ;
F_16 ( V_8 ) ;
F_20 ( V_8 ) ;
F_21 ( V_8 ) ;
F_24 ( V_8 ) ;
V_8 = V_8 -> V_31 ;
} while ( V_8 != V_32 );
F_19 ( V_2 ) ;
F_10 ( V_2 ) ;
}
F_51 ( & V_52 ) ;
F_52 () ;
}
}
unsigned F_64 ( struct V_2 * V_2 ,
unsigned V_66 , unsigned V_67 )
{
unsigned V_68 , V_69 ;
struct V_1 * V_8 , * V_32 ;
unsigned V_70 = 0 ;
for ( V_8 = V_32 = F_32 ( V_2 ) , V_68 = 0 ;
V_8 != V_32 || ! V_68 ;
V_68 = V_69 , V_8 = V_8 -> V_31 ) {
V_69 = V_68 + V_8 -> V_26 ;
if ( V_69 > V_66 && V_68 < V_67 && ! F_33 ( V_8 ) )
V_70 ++ ;
}
return V_70 ;
}
void F_65 ( struct V_11 * V_12 , struct V_10 * V_10 ,
struct V_71 * V_72 )
{
V_12 -> V_36 = V_10 ;
V_12 -> V_39 = 0 ;
F_66 ( V_12 , V_73 ) ;
V_12 -> V_74 = NULL ;
V_12 -> V_71 = V_72 ;
V_12 -> V_75 = & V_76 ;
}
int F_19 ( struct V_2 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
if ( V_12 ) {
F_58 ( & V_12 -> V_62 ) ;
if ( F_67 ( V_77 , & V_2 -> V_39 ) ) {
F_68 ( & V_12 -> V_63 ,
F_69 ( V_2 ) ,
V_55 ) ;
F_60 ( & V_12 -> V_62 ) ;
return F_70 ( V_2 ) ;
}
F_60 ( & V_12 -> V_62 ) ;
return 0 ;
}
return F_71 ( V_2 ) ;
}
unsigned long F_72 ( struct V_10 * V_10 ,
T_2 V_78 ,
T_2 * V_13 )
{
unsigned int V_40 ;
T_1 V_4 ;
unsigned int V_79 ;
unsigned long V_80 = 0 ;
T_2 V_81 ;
struct V_51 V_52 ;
struct V_2 * V_2 ;
if ( V_10 -> V_82 -> V_64 == 0 )
return 0 ;
V_4 = V_78 >> ( V_9 - V_10 -> V_14 ) ;
V_79 = 1U << ( V_9 - V_10 -> V_14 ) ;
F_44 ( & V_52 , 0 ) ;
V_54:
V_52 . V_83 = F_73 ( V_10 -> V_82 , V_4 , V_56 ,
V_52 . V_57 ) ;
if ( V_52 . V_83 == 0 )
return V_80 ;
if ( V_80 > 0 && V_52 . V_57 [ 0 ] -> V_4 > V_4 )
goto V_84;
V_81 = V_52 . V_57 [ 0 ] -> V_4 << ( V_9 - V_10 -> V_14 ) ;
V_40 = 0 ;
do {
V_2 = V_52 . V_57 [ V_40 ] ;
F_47 ( V_2 ) ;
if ( F_2 ( V_2 ) ) {
struct V_1 * V_8 , * V_32 ;
V_8 = V_32 = F_32 ( V_2 ) ;
do {
if ( V_81 < V_78 )
continue;
if ( F_74 ( V_8 ) ) {
if ( V_80 == 0 )
* V_13 = V_81 ;
V_80 ++ ;
} else if ( V_80 > 0 ) {
goto V_85;
}
} while ( ++ V_81 , V_8 = V_8 -> V_31 , V_8 != V_32 );
} else {
if ( V_80 > 0 )
goto V_85;
V_81 += V_79 ;
}
F_10 ( V_2 ) ;
} while ( ++ V_40 < F_46 ( & V_52 ) );
V_4 = V_2 -> V_4 + 1 ;
F_51 ( & V_52 ) ;
F_52 () ;
goto V_54;
V_85:
F_10 ( V_2 ) ;
V_84:
F_51 ( & V_52 ) ;
return V_80 ;
}
