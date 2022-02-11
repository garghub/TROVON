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
( F_13 ( V_17 ) | F_13 ( V_18 ) | F_13 ( V_19 ) |
F_13 ( V_20 ) | F_13 ( V_21 ) |
F_13 ( V_22 ) | F_13 ( V_23 ) ) ;
F_14 ( V_8 ) ;
F_15 ( & V_8 -> V_6 , V_16 , 0 ) ;
if ( F_16 ( V_2 ) )
F_17 ( V_2 ) ;
V_8 -> V_24 = - 1 ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_8 ) ;
F_21 ( V_8 ) ;
}
void F_22 ( struct V_1 * V_25 , struct V_1 * V_26 )
{
void * V_27 , * V_28 ;
unsigned long V_29 ;
struct V_2 * V_30 = V_26 -> V_15 , * V_31 = V_25 -> V_15 ;
struct V_1 * V_8 ;
V_27 = F_23 ( V_30 ) ;
V_28 = F_23 ( V_31 ) ;
memcpy ( V_28 + F_24 ( V_25 ) , V_27 + F_24 ( V_26 ) , V_26 -> V_32 ) ;
F_25 ( V_28 ) ;
F_25 ( V_27 ) ;
V_25 -> V_6 = V_26 -> V_6 & V_33 ;
V_25 -> V_24 = V_26 -> V_24 ;
V_25 -> V_34 = V_26 -> V_34 ;
V_8 = V_25 ;
V_29 = V_26 -> V_6 & ( F_13 ( V_17 ) | F_13 ( V_19 ) ) ;
while ( ( V_8 = V_8 -> V_35 ) != V_25 ) {
F_14 ( V_8 ) ;
V_29 &= V_8 -> V_6 ;
F_20 ( V_8 ) ;
}
if ( V_29 & F_13 ( V_17 ) )
F_26 ( V_31 ) ;
else
F_18 ( V_31 ) ;
if ( V_29 & F_13 ( V_19 ) )
F_27 ( V_31 ) ;
else
F_19 ( V_31 ) ;
}
int F_16 ( struct V_2 * V_2 )
{
struct V_1 * V_8 , * V_36 ;
V_8 = V_36 = F_28 ( V_2 ) ;
do {
if ( F_29 ( V_8 ) )
return 0 ;
V_8 = V_8 -> V_35 ;
} while ( V_8 != V_36 );
return 1 ;
}
void F_30 ( struct V_2 * V_2 )
{
struct V_11 * V_37 ;
unsigned long V_38 ;
if ( F_9 ( ! V_2 ) ) {
F_31 ( V_39 L_1 ) ;
return;
}
V_37 = V_2 -> V_12 ;
V_38 = V_37 ? V_37 -> V_40 -> V_41 : 0 ;
F_31 ( V_39 L_2
L_3 ,
V_2 , F_32 ( V_2 ) ,
( unsigned long long ) V_2 -> V_4 , V_2 -> V_42 , V_37 , V_38 ) ;
if ( F_2 ( V_2 ) ) {
struct V_1 * V_8 , * V_36 ;
int V_43 = 0 ;
V_8 = V_36 = F_28 ( V_2 ) ;
do {
F_31 ( V_39
L_4 ,
V_43 ++ , V_8 , F_33 ( & V_8 -> V_44 ) ,
( unsigned long long ) V_8 -> V_24 , V_8 -> V_6 ) ;
V_8 = V_8 -> V_35 ;
} while ( V_8 != V_36 );
}
}
static void F_34 ( struct V_2 * V_45 , struct V_2 * V_46 , int V_47 )
{
struct V_1 * V_25 , * V_48 , * V_26 , * V_49 ;
unsigned long V_50 = V_33 ;
F_35 ( F_36 ( V_45 ) ) ;
V_26 = V_49 = F_28 ( V_46 ) ;
if ( ! F_2 ( V_45 ) )
F_3 ( V_45 , V_26 -> V_32 , 0 ) ;
if ( V_47 )
V_50 |= F_13 ( V_18 ) ;
V_25 = V_48 = F_28 ( V_45 ) ;
do {
F_14 ( V_26 ) ;
F_14 ( V_25 ) ;
V_25 -> V_6 = V_26 -> V_6 & V_50 ;
V_25 -> V_24 = V_26 -> V_24 ;
V_25 -> V_34 = V_26 -> V_34 ;
V_26 = V_26 -> V_35 ;
V_25 = V_25 -> V_35 ;
} while ( V_25 != V_48 );
F_37 ( V_45 , V_46 ) ;
if ( F_38 ( V_46 ) && ! F_38 ( V_45 ) )
F_26 ( V_45 ) ;
else if ( ! F_38 ( V_46 ) && F_38 ( V_45 ) )
F_18 ( V_45 ) ;
if ( F_39 ( V_46 ) && ! F_39 ( V_45 ) )
F_27 ( V_45 ) ;
else if ( ! F_39 ( V_46 ) && F_39 ( V_45 ) )
F_19 ( V_45 ) ;
do {
F_20 ( V_26 ) ;
F_20 ( V_25 ) ;
V_26 = V_26 -> V_35 ;
V_25 = V_25 -> V_35 ;
} while ( V_25 != V_48 );
}
int F_40 ( struct V_11 * V_51 ,
struct V_11 * V_52 )
{
struct V_53 V_54 ;
unsigned int V_43 ;
T_1 V_4 = 0 ;
int V_55 = 0 ;
F_41 ( & V_54 , 0 ) ;
V_56:
if ( ! F_42 ( & V_54 , V_52 , & V_4 , V_57 ,
V_58 ) )
return 0 ;
for ( V_43 = 0 ; V_43 < F_43 ( & V_54 ) ; V_43 ++ ) {
struct V_2 * V_2 = V_54 . V_59 [ V_43 ] , * V_31 ;
F_44 ( V_2 ) ;
if ( F_9 ( ! F_45 ( V_2 ) ) )
F_46 ( V_2 , L_5 ) ;
V_31 = F_8 ( V_51 , V_2 -> V_4 ) ;
if ( F_9 ( ! V_31 ) ) {
V_55 = - V_60 ;
F_10 ( V_2 ) ;
break;
}
if ( F_9 ( ! F_2 ( V_2 ) ) )
F_46 ( V_2 ,
L_6 ) ;
F_34 ( V_31 , V_2 , 1 ) ;
F_47 ( V_31 ) ;
F_10 ( V_31 ) ;
F_11 ( V_31 ) ;
F_10 ( V_2 ) ;
}
F_48 ( & V_54 ) ;
F_49 () ;
if ( F_50 ( ! V_55 ) )
goto V_56;
return V_55 ;
}
void F_51 ( struct V_11 * V_51 ,
struct V_11 * V_52 )
{
struct V_53 V_54 ;
unsigned int V_43 , V_61 ;
T_1 V_4 = 0 ;
int V_55 ;
F_41 ( & V_54 , 0 ) ;
V_56:
V_61 = F_52 ( & V_54 , V_52 , V_4 , V_58 ) ;
if ( ! V_61 )
return;
V_4 = V_54 . V_59 [ V_61 - 1 ] -> V_4 + 1 ;
for ( V_43 = 0 ; V_43 < F_43 ( & V_54 ) ; V_43 ++ ) {
struct V_2 * V_2 = V_54 . V_59 [ V_43 ] , * V_31 ;
T_1 V_62 = V_2 -> V_4 ;
F_44 ( V_2 ) ;
V_31 = F_53 ( V_51 , V_62 ) ;
if ( V_31 ) {
F_54 ( F_45 ( V_31 ) ) ;
F_34 ( V_31 , V_2 , 0 ) ;
F_10 ( V_31 ) ;
F_11 ( V_31 ) ;
} else {
struct V_2 * V_63 ;
F_55 ( & V_52 -> V_64 ) ;
V_63 = F_56 ( & V_52 -> V_65 , V_62 ) ;
F_54 ( V_63 != V_2 ) ;
V_52 -> V_66 -- ;
F_57 ( & V_52 -> V_64 ) ;
F_55 ( & V_51 -> V_64 ) ;
V_55 = F_58 ( & V_51 -> V_65 , V_62 , V_2 ) ;
if ( F_9 ( V_55 < 0 ) ) {
F_54 ( V_55 == - V_67 ) ;
V_2 -> V_12 = NULL ;
F_11 ( V_2 ) ;
} else {
V_2 -> V_12 = V_51 ;
V_51 -> V_66 ++ ;
if ( F_45 ( V_2 ) )
F_59 ( & V_51 -> V_65 ,
V_62 ,
V_57 ) ;
}
F_57 ( & V_51 -> V_64 ) ;
}
F_10 ( V_2 ) ;
}
F_48 ( & V_54 ) ;
F_49 () ;
goto V_56;
}
void F_60 ( struct V_11 * V_12 , bool V_68 )
{
struct V_53 V_54 ;
unsigned int V_43 ;
T_1 V_4 = 0 ;
F_41 ( & V_54 , 0 ) ;
while ( F_42 ( & V_54 , V_12 , & V_4 , V_57 ,
V_58 ) ) {
for ( V_43 = 0 ; V_43 < F_43 ( & V_54 ) ; V_43 ++ ) {
struct V_2 * V_2 = V_54 . V_59 [ V_43 ] ;
F_44 ( V_2 ) ;
F_61 ( V_2 , V_68 ) ;
F_10 ( V_2 ) ;
}
F_48 ( & V_54 ) ;
F_49 () ;
}
}
void F_61 ( struct V_2 * V_2 , bool V_68 )
{
struct V_10 * V_10 = V_2 -> V_12 -> V_40 ;
struct V_69 * V_70 = V_10 -> V_71 ;
F_35 ( ! F_62 ( V_2 ) ) ;
if ( ! V_68 )
F_63 ( V_70 , V_72 ,
L_7 ,
F_64 ( V_2 ) , V_10 -> V_41 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
if ( F_2 ( V_2 ) ) {
struct V_1 * V_8 , * V_36 ;
const unsigned long V_16 =
( F_13 ( V_17 ) | F_13 ( V_18 ) | F_13 ( V_19 ) |
F_13 ( V_20 ) | F_13 ( V_21 ) |
F_13 ( V_22 ) | F_13 ( V_23 ) ) ;
V_8 = V_36 = F_28 ( V_2 ) ;
do {
F_14 ( V_8 ) ;
if ( ! V_68 )
F_63 ( V_70 , V_72 ,
L_8 ,
( V_73 ) V_8 -> V_24 , V_8 -> V_32 ) ;
F_15 ( & V_8 -> V_6 , V_16 , 0 ) ;
F_20 ( V_8 ) ;
} while ( V_8 = V_8 -> V_35 , V_8 != V_36 );
}
F_17 ( V_2 ) ;
}
unsigned int F_65 ( struct V_2 * V_2 ,
unsigned int V_74 , unsigned int V_75 )
{
unsigned int V_76 , V_77 ;
struct V_1 * V_8 , * V_36 ;
unsigned int V_78 = 0 ;
for ( V_8 = V_36 = F_28 ( V_2 ) , V_76 = 0 ;
V_8 != V_36 || ! V_76 ;
V_76 = V_77 , V_8 = V_8 -> V_35 ) {
V_77 = V_76 + V_8 -> V_32 ;
if ( V_77 > V_74 && V_76 < V_75 && ! F_29 ( V_8 ) )
V_78 ++ ;
}
return V_78 ;
}
void F_66 ( struct V_11 * V_12 , struct V_10 * V_10 )
{
V_12 -> V_40 = V_10 ;
V_12 -> V_42 = 0 ;
F_67 ( V_12 , V_79 ) ;
V_12 -> V_80 = NULL ;
V_12 -> V_81 = & V_82 ;
}
int F_17 ( struct V_2 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
if ( V_12 ) {
F_55 ( & V_12 -> V_64 ) ;
if ( F_68 ( V_83 , & V_2 -> V_42 ) ) {
F_69 ( & V_12 -> V_65 ,
F_70 ( V_2 ) ,
V_57 ) ;
F_57 ( & V_12 -> V_64 ) ;
return F_71 ( V_2 ) ;
}
F_57 ( & V_12 -> V_64 ) ;
return 0 ;
}
return F_72 ( V_2 ) ;
}
unsigned long F_73 ( struct V_10 * V_10 ,
T_2 V_84 ,
T_2 * V_13 )
{
unsigned int V_43 ;
T_1 V_4 ;
unsigned int V_85 ;
unsigned long V_86 = 0 ;
T_2 V_87 ;
struct V_53 V_54 ;
struct V_2 * V_2 ;
if ( V_10 -> V_88 -> V_66 == 0 )
return 0 ;
V_4 = V_84 >> ( V_9 - V_10 -> V_14 ) ;
V_85 = 1U << ( V_9 - V_10 -> V_14 ) ;
F_41 ( & V_54 , 0 ) ;
V_56:
V_54 . V_89 = F_74 ( V_10 -> V_88 , V_4 , V_58 ,
V_54 . V_59 ) ;
if ( V_54 . V_89 == 0 )
return V_86 ;
if ( V_86 > 0 && V_54 . V_59 [ 0 ] -> V_4 > V_4 )
goto V_90;
V_87 = V_54 . V_59 [ 0 ] -> V_4 << ( V_9 - V_10 -> V_14 ) ;
V_43 = 0 ;
do {
V_2 = V_54 . V_59 [ V_43 ] ;
F_44 ( V_2 ) ;
if ( F_2 ( V_2 ) ) {
struct V_1 * V_8 , * V_36 ;
V_8 = V_36 = F_28 ( V_2 ) ;
do {
if ( V_87 < V_84 )
continue;
if ( F_75 ( V_8 ) ) {
if ( V_86 == 0 )
* V_13 = V_87 ;
V_86 ++ ;
} else if ( V_86 > 0 ) {
goto V_91;
}
} while ( ++ V_87 , V_8 = V_8 -> V_35 , V_8 != V_36 );
} else {
if ( V_86 > 0 )
goto V_91;
V_87 += V_85 ;
}
F_10 ( V_2 ) ;
} while ( ++ V_43 < F_43 ( & V_54 ) );
V_4 = V_2 -> V_4 + 1 ;
F_48 ( & V_54 ) ;
F_49 () ;
goto V_56;
V_91:
F_10 ( V_2 ) ;
V_90:
F_48 ( & V_54 ) ;
return V_86 ;
}
