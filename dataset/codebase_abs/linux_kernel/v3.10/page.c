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
V_19 = F_27 ( V_22 ) ;
V_20 = F_27 ( V_23 ) ;
memcpy ( V_20 + F_28 ( V_17 ) , V_19 + F_28 ( V_18 ) , V_18 -> V_24 ) ;
F_29 ( V_20 ) ;
F_29 ( V_19 ) ;
V_17 -> V_6 = V_18 -> V_6 & V_25 ;
V_17 -> V_16 = V_18 -> V_16 ;
V_17 -> V_26 = V_18 -> V_26 ;
V_8 = V_17 ;
V_21 = V_18 -> V_6 & ( ( 1UL << V_27 ) | ( 1UL << V_28 ) ) ;
while ( ( V_8 = V_8 -> V_29 ) != V_17 ) {
F_13 ( V_8 ) ;
V_21 &= V_8 -> V_6 ;
F_24 ( V_8 ) ;
}
if ( V_21 & ( 1UL << V_27 ) )
F_30 ( V_23 ) ;
else
F_22 ( V_23 ) ;
if ( V_21 & ( 1UL << V_28 ) )
F_31 ( V_23 ) ;
else
F_23 ( V_23 ) ;
}
int F_18 ( struct V_2 * V_2 )
{
struct V_1 * V_8 , * V_30 ;
V_8 = V_30 = F_32 ( V_2 ) ;
do {
if ( F_33 ( V_8 ) )
return 0 ;
V_8 = V_8 -> V_29 ;
} while ( V_8 != V_30 );
return 1 ;
}
void F_34 ( struct V_2 * V_2 )
{
struct V_11 * V_31 ;
unsigned long V_32 ;
if ( F_9 ( ! V_2 ) ) {
F_35 ( V_33 L_1 ) ;
return;
}
V_31 = V_2 -> V_12 ;
V_32 = V_31 ? V_31 -> V_34 -> V_35 : 0 ;
F_35 ( V_33 L_2
L_3 ,
V_2 , F_36 ( & V_2 -> V_36 ) ,
( unsigned long long ) V_2 -> V_4 , V_2 -> V_37 , V_31 , V_32 ) ;
if ( F_2 ( V_2 ) ) {
struct V_1 * V_8 , * V_30 ;
int V_38 = 0 ;
V_8 = V_30 = F_32 ( V_2 ) ;
do {
F_35 ( V_33
L_4 ,
V_38 ++ , V_8 , F_36 ( & V_8 -> V_39 ) ,
( unsigned long long ) V_8 -> V_16 , V_8 -> V_6 ) ;
V_8 = V_8 -> V_29 ;
} while ( V_8 != V_30 );
}
}
static void F_37 ( struct V_2 * V_40 , struct V_2 * V_41 , int V_42 )
{
struct V_1 * V_17 , * V_43 , * V_18 , * V_44 ;
unsigned long V_45 = V_25 ;
F_38 ( F_39 ( V_40 ) ) ;
V_18 = V_44 = F_32 ( V_41 ) ;
if ( ! F_2 ( V_40 ) )
F_3 ( V_40 , V_18 -> V_24 , 0 ) ;
if ( V_42 )
V_45 |= ( 1UL << V_46 ) ;
V_17 = V_43 = F_32 ( V_40 ) ;
do {
F_13 ( V_18 ) ;
F_13 ( V_17 ) ;
V_17 -> V_6 = V_18 -> V_6 & V_45 ;
V_17 -> V_16 = V_18 -> V_16 ;
V_17 -> V_26 = V_18 -> V_26 ;
V_18 = V_18 -> V_29 ;
V_17 = V_17 -> V_29 ;
} while ( V_17 != V_43 );
F_40 ( V_40 , V_41 ) ;
if ( F_41 ( V_41 ) && ! F_41 ( V_40 ) )
F_30 ( V_40 ) ;
else if ( ! F_41 ( V_41 ) && F_41 ( V_40 ) )
F_22 ( V_40 ) ;
if ( F_42 ( V_41 ) && ! F_42 ( V_40 ) )
F_31 ( V_40 ) ;
else if ( ! F_42 ( V_41 ) && F_42 ( V_40 ) )
F_23 ( V_40 ) ;
do {
F_24 ( V_18 ) ;
F_24 ( V_17 ) ;
V_18 = V_18 -> V_29 ;
V_17 = V_17 -> V_29 ;
} while ( V_17 != V_43 );
}
int F_43 ( struct V_11 * V_47 ,
struct V_11 * V_48 )
{
struct V_49 V_50 ;
unsigned int V_38 ;
T_1 V_4 = 0 ;
int V_51 = 0 ;
F_44 ( & V_50 , 0 ) ;
V_52:
if ( ! F_45 ( & V_50 , V_48 , & V_4 , V_53 ,
V_54 ) )
return 0 ;
for ( V_38 = 0 ; V_38 < F_46 ( & V_50 ) ; V_38 ++ ) {
struct V_2 * V_2 = V_50 . V_55 [ V_38 ] , * V_23 ;
F_47 ( V_2 ) ;
if ( F_9 ( ! F_48 ( V_2 ) ) )
F_49 ( V_2 , L_5 ) ;
V_23 = F_8 ( V_47 , V_2 -> V_4 ) ;
if ( F_9 ( ! V_23 ) ) {
V_51 = - V_56 ;
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
F_51 ( & V_50 ) ;
F_52 () ;
if ( F_53 ( ! V_51 ) )
goto V_52;
return V_51 ;
}
void F_54 ( struct V_11 * V_47 ,
struct V_11 * V_48 )
{
struct V_49 V_50 ;
unsigned int V_38 , V_57 ;
T_1 V_4 = 0 ;
int V_51 ;
F_44 ( & V_50 , 0 ) ;
V_52:
V_57 = F_55 ( & V_50 , V_48 , V_4 , V_54 ) ;
if ( ! V_57 )
return;
V_4 = V_50 . V_55 [ V_57 - 1 ] -> V_4 + 1 ;
for ( V_38 = 0 ; V_38 < F_46 ( & V_50 ) ; V_38 ++ ) {
struct V_2 * V_2 = V_50 . V_55 [ V_38 ] , * V_23 ;
T_1 V_58 = V_2 -> V_4 ;
F_47 ( V_2 ) ;
V_23 = F_56 ( V_47 , V_58 ) ;
if ( V_23 ) {
F_57 ( F_48 ( V_23 ) ) ;
F_37 ( V_23 , V_2 , 0 ) ;
F_10 ( V_23 ) ;
F_11 ( V_23 ) ;
} else {
struct V_2 * V_59 ;
F_58 ( & V_48 -> V_60 ) ;
V_59 = F_59 ( & V_48 -> V_61 , V_58 ) ;
F_57 ( V_59 != V_2 ) ;
V_48 -> V_62 -- ;
F_60 ( & V_48 -> V_60 ) ;
F_58 ( & V_47 -> V_60 ) ;
V_51 = F_61 ( & V_47 -> V_61 , V_58 , V_2 ) ;
if ( F_9 ( V_51 < 0 ) ) {
F_57 ( V_51 == - V_63 ) ;
V_2 -> V_12 = NULL ;
F_11 ( V_2 ) ;
} else {
V_2 -> V_12 = V_47 ;
V_47 -> V_62 ++ ;
if ( F_48 ( V_2 ) )
F_62 ( & V_47 -> V_61 ,
V_58 ,
V_53 ) ;
}
F_60 ( & V_47 -> V_60 ) ;
}
F_10 ( V_2 ) ;
}
F_51 ( & V_50 ) ;
F_52 () ;
goto V_52;
}
void F_63 ( struct V_11 * V_12 , bool V_64 )
{
struct V_49 V_50 ;
unsigned int V_38 ;
T_1 V_4 = 0 ;
F_44 ( & V_50 , 0 ) ;
while ( F_45 ( & V_50 , V_12 , & V_4 , V_53 ,
V_54 ) ) {
for ( V_38 = 0 ; V_38 < F_46 ( & V_50 ) ; V_38 ++ ) {
struct V_2 * V_2 = V_50 . V_55 [ V_38 ] ;
F_47 ( V_2 ) ;
F_64 ( V_2 , V_64 ) ;
F_10 ( V_2 ) ;
}
F_51 ( & V_50 ) ;
F_52 () ;
}
}
void F_64 ( struct V_2 * V_2 , bool V_64 )
{
struct V_10 * V_10 = V_2 -> V_12 -> V_34 ;
struct V_65 * V_66 = V_10 -> V_67 ;
F_38 ( ! F_65 ( V_2 ) ) ;
if ( ! V_64 ) {
F_66 ( V_66 , V_68 ,
L_7 ,
F_67 ( V_2 ) , V_10 -> V_35 ) ;
}
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
if ( F_2 ( V_2 ) ) {
struct V_1 * V_8 , * V_30 ;
V_8 = V_30 = F_32 ( V_2 ) ;
do {
F_13 ( V_8 ) ;
if ( ! V_64 ) {
F_66 ( V_66 , V_68 ,
L_8 ,
( V_69 ) V_8 -> V_16 , V_8 -> V_24 ) ;
}
F_17 ( V_8 ) ;
F_14 ( V_8 ) ;
F_15 ( V_8 ) ;
F_16 ( V_8 ) ;
F_20 ( V_8 ) ;
F_21 ( V_8 ) ;
F_24 ( V_8 ) ;
} while ( V_8 = V_8 -> V_29 , V_8 != V_30 );
}
F_19 ( V_2 ) ;
}
unsigned F_68 ( struct V_2 * V_2 ,
unsigned V_70 , unsigned V_71 )
{
unsigned V_72 , V_73 ;
struct V_1 * V_8 , * V_30 ;
unsigned V_74 = 0 ;
for ( V_8 = V_30 = F_32 ( V_2 ) , V_72 = 0 ;
V_8 != V_30 || ! V_72 ;
V_72 = V_73 , V_8 = V_8 -> V_29 ) {
V_73 = V_72 + V_8 -> V_24 ;
if ( V_73 > V_70 && V_72 < V_71 && ! F_33 ( V_8 ) )
V_74 ++ ;
}
return V_74 ;
}
void F_69 ( struct V_11 * V_12 , struct V_10 * V_10 ,
struct V_75 * V_76 )
{
V_12 -> V_34 = V_10 ;
V_12 -> V_37 = 0 ;
F_70 ( V_12 , V_77 ) ;
V_12 -> V_78 = NULL ;
V_12 -> V_75 = V_76 ;
V_12 -> V_79 = & V_80 ;
}
int F_19 ( struct V_2 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
if ( V_12 ) {
F_58 ( & V_12 -> V_60 ) ;
if ( F_71 ( V_81 , & V_2 -> V_37 ) ) {
F_72 ( & V_12 -> V_61 ,
F_73 ( V_2 ) ,
V_53 ) ;
F_60 ( & V_12 -> V_60 ) ;
return F_74 ( V_2 ) ;
}
F_60 ( & V_12 -> V_60 ) ;
return 0 ;
}
return F_75 ( V_2 ) ;
}
unsigned long F_76 ( struct V_10 * V_10 ,
T_2 V_82 ,
T_2 * V_13 )
{
unsigned int V_38 ;
T_1 V_4 ;
unsigned int V_83 ;
unsigned long V_84 = 0 ;
T_2 V_85 ;
struct V_49 V_50 ;
struct V_2 * V_2 ;
if ( V_10 -> V_86 -> V_62 == 0 )
return 0 ;
V_4 = V_82 >> ( V_9 - V_10 -> V_14 ) ;
V_83 = 1U << ( V_9 - V_10 -> V_14 ) ;
F_44 ( & V_50 , 0 ) ;
V_52:
V_50 . V_87 = F_77 ( V_10 -> V_86 , V_4 , V_54 ,
V_50 . V_55 ) ;
if ( V_50 . V_87 == 0 )
return V_84 ;
if ( V_84 > 0 && V_50 . V_55 [ 0 ] -> V_4 > V_4 )
goto V_88;
V_85 = V_50 . V_55 [ 0 ] -> V_4 << ( V_9 - V_10 -> V_14 ) ;
V_38 = 0 ;
do {
V_2 = V_50 . V_55 [ V_38 ] ;
F_47 ( V_2 ) ;
if ( F_2 ( V_2 ) ) {
struct V_1 * V_8 , * V_30 ;
V_8 = V_30 = F_32 ( V_2 ) ;
do {
if ( V_85 < V_82 )
continue;
if ( F_78 ( V_8 ) ) {
if ( V_84 == 0 )
* V_13 = V_85 ;
V_84 ++ ;
} else if ( V_84 > 0 ) {
goto V_89;
}
} while ( ++ V_85 , V_8 = V_8 -> V_29 , V_8 != V_30 );
} else {
if ( V_84 > 0 )
goto V_89;
V_85 += V_83 ;
}
F_10 ( V_2 ) ;
} while ( ++ V_38 < F_46 ( & V_50 ) );
V_4 = V_2 -> V_4 + 1 ;
F_51 ( & V_50 ) ;
F_52 () ;
goto V_52;
V_89:
F_10 ( V_2 ) ;
V_88:
F_51 ( & V_50 ) ;
return V_84 ;
}
