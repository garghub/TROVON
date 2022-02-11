static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 )
{
struct V_5 * V_6 ;
void * * V_7 ;
F_2 ( & V_2 -> V_8 ) ;
if ( ! F_3 ( & V_2 -> V_9 , V_3 , & V_6 , & V_7 ) )
goto V_10;
if ( * V_7 != V_4 )
goto V_10;
F_4 ( & V_2 -> V_9 , V_6 , V_7 , NULL ,
V_11 , V_2 ) ;
V_2 -> V_12 -- ;
V_10:
F_5 ( & V_2 -> V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
T_1 V_3 , void * V_4 )
{
if ( F_7 ( V_2 ) )
return;
if ( F_8 ( V_2 ) ) {
F_9 ( V_2 , V_3 ) ;
return;
}
F_1 ( V_2 , V_3 , V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_3 , void * V_4 )
{
if ( F_7 ( V_2 ) || F_8 ( V_2 ) )
return 1 ;
F_1 ( V_2 , V_3 , V_4 ) ;
return 1 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_1 V_3 , void * V_4 )
{
if ( F_7 ( V_2 ) )
return 1 ;
if ( F_8 ( V_2 ) )
return F_12 ( V_2 , V_3 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
return 1 ;
}
void F_13 ( struct V_13 * V_13 , unsigned int V_14 ,
unsigned int V_15 )
{
void (* F_14)( struct V_13 * , unsigned int , unsigned int );
F_14 = V_13 -> V_2 -> V_16 -> F_14 ;
#ifdef F_15
if ( ! F_14 )
F_14 = V_17 ;
#endif
if ( F_14 )
(* F_14)( V_13 , V_14 , V_15 ) ;
}
static int
F_16 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
if ( V_13 -> V_2 != V_2 )
return - V_18 ;
if ( F_17 ( V_13 ) )
F_13 ( V_13 , 0 , V_19 ) ;
F_18 ( V_13 ) ;
F_19 ( V_13 ) ;
F_20 ( V_13 ) ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
int V_20 ;
if ( V_13 -> V_2 != V_2 )
return 0 ;
if ( F_17 ( V_13 ) && ! F_22 ( V_13 , 0 ) )
return 0 ;
V_20 = F_23 ( V_2 , V_13 ) ;
return V_20 ;
}
int F_24 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
T_2 V_21 ;
F_25 ( F_26 ( V_13 ) , V_13 ) ;
V_21 = F_27 ( V_13 ) ? V_22 : V_19 ;
if ( F_28 ( V_13 ) ) {
F_29 ( V_2 ,
( T_2 ) V_13 -> V_3 << V_23 ,
V_21 , 0 ) ;
}
return F_16 ( V_2 , V_13 ) ;
}
int F_30 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
if ( ! V_2 )
return - V_24 ;
if ( ! F_31 ( V_2 -> V_25 -> V_26 ) )
return - V_18 ;
return F_24 ( V_2 , V_13 ) ;
}
int F_32 ( struct V_13 * V_13 )
{
struct V_1 * V_2 = F_33 ( V_13 ) ;
if ( ! V_2 )
return 0 ;
if ( F_34 ( V_13 ) || F_35 ( V_13 ) )
return 0 ;
if ( F_28 ( V_13 ) )
return 0 ;
return F_21 ( V_2 , V_13 ) ;
}
void F_36 ( struct V_1 * V_2 ,
T_2 V_27 , T_2 V_28 )
{
T_1 V_29 ;
T_1 V_30 ;
unsigned int V_31 ;
unsigned int V_32 ;
struct V_33 V_34 ;
T_1 V_35 [ V_36 ] ;
T_1 V_3 ;
int V_37 ;
if ( V_2 -> V_38 == 0 && V_2 -> V_12 == 0 )
goto V_39;
V_31 = V_27 & ( V_19 - 1 ) ;
V_32 = ( V_28 + 1 ) & ( V_19 - 1 ) ;
V_29 = ( V_27 + V_19 - 1 ) >> V_23 ;
if ( V_28 == - 1 )
V_30 = - 1 ;
else
V_30 = ( V_28 + 1 ) >> V_23 ;
F_37 ( & V_34 , 0 ) ;
V_3 = V_29 ;
while ( V_3 < V_30 && F_38 ( & V_34 , V_2 , V_3 ,
F_39 ( V_30 - V_3 , ( T_1 ) V_36 ) ,
V_35 ) ) {
for ( V_37 = 0 ; V_37 < F_40 ( & V_34 ) ; V_37 ++ ) {
struct V_13 * V_13 = V_34 . V_40 [ V_37 ] ;
V_3 = V_35 [ V_37 ] ;
if ( V_3 >= V_30 )
break;
if ( F_41 ( V_13 ) ) {
F_6 ( V_2 , V_3 ,
V_13 ) ;
continue;
}
if ( ! F_42 ( V_13 ) )
continue;
F_43 ( F_44 ( V_13 ) != V_3 ) ;
if ( F_35 ( V_13 ) ) {
F_45 ( V_13 ) ;
continue;
}
F_24 ( V_2 , V_13 ) ;
F_45 ( V_13 ) ;
}
F_46 ( & V_34 ) ;
F_47 ( & V_34 ) ;
F_48 () ;
V_3 ++ ;
}
if ( V_31 ) {
struct V_13 * V_13 = F_49 ( V_2 , V_29 - 1 ) ;
if ( V_13 ) {
unsigned int V_41 = V_19 ;
if ( V_29 > V_30 ) {
V_41 = V_32 ;
V_32 = 0 ;
}
F_50 ( V_13 ) ;
F_51 ( V_13 , V_31 , V_41 ) ;
F_52 ( V_2 , V_13 ) ;
if ( F_17 ( V_13 ) )
F_13 ( V_13 , V_31 ,
V_41 - V_31 ) ;
F_45 ( V_13 ) ;
F_53 ( V_13 ) ;
}
}
if ( V_32 ) {
struct V_13 * V_13 = F_49 ( V_2 , V_30 ) ;
if ( V_13 ) {
F_50 ( V_13 ) ;
F_51 ( V_13 , 0 , V_32 ) ;
F_52 ( V_2 , V_13 ) ;
if ( F_17 ( V_13 ) )
F_13 ( V_13 , 0 ,
V_32 ) ;
F_45 ( V_13 ) ;
F_53 ( V_13 ) ;
}
}
if ( V_29 >= V_30 )
goto V_39;
V_3 = V_29 ;
for ( ; ; ) {
F_48 () ;
if ( ! F_38 ( & V_34 , V_2 , V_3 ,
F_39 ( V_30 - V_3 , ( T_1 ) V_36 ) , V_35 ) ) {
if ( V_3 == V_29 )
break;
V_3 = V_29 ;
continue;
}
if ( V_3 == V_29 && V_35 [ 0 ] >= V_30 ) {
F_46 ( & V_34 ) ;
F_47 ( & V_34 ) ;
break;
}
for ( V_37 = 0 ; V_37 < F_40 ( & V_34 ) ; V_37 ++ ) {
struct V_13 * V_13 = V_34 . V_40 [ V_37 ] ;
V_3 = V_35 [ V_37 ] ;
if ( V_3 >= V_30 ) {
V_3 = V_29 - 1 ;
break;
}
if ( F_41 ( V_13 ) ) {
F_6 ( V_2 , V_3 ,
V_13 ) ;
continue;
}
F_54 ( V_13 ) ;
F_43 ( F_44 ( V_13 ) != V_3 ) ;
F_50 ( V_13 ) ;
F_24 ( V_2 , V_13 ) ;
F_45 ( V_13 ) ;
}
F_46 ( & V_34 ) ;
F_47 ( & V_34 ) ;
V_3 ++ ;
}
V_39:
F_55 ( V_2 ) ;
}
void F_56 ( struct V_1 * V_2 , T_2 V_27 )
{
F_36 ( V_2 , V_27 , ( T_2 ) - 1 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
unsigned long V_38 ;
F_58 ( V_2 ) ;
V_38 = V_2 -> V_38 ;
F_59 () ;
V_12 = V_2 -> V_12 ;
if ( V_38 || V_12 ) {
F_2 ( & V_2 -> V_8 ) ;
F_5 ( & V_2 -> V_8 ) ;
F_56 ( V_2 , 0 ) ;
}
}
unsigned long F_60 ( struct V_1 * V_2 ,
T_1 V_29 , T_1 V_30 )
{
T_1 V_35 [ V_36 ] ;
struct V_33 V_34 ;
T_1 V_3 = V_29 ;
unsigned long V_20 ;
unsigned long V_42 = 0 ;
int V_37 ;
F_37 ( & V_34 , 0 ) ;
while ( V_3 <= V_30 && F_38 ( & V_34 , V_2 , V_3 ,
F_39 ( V_30 - V_3 , ( T_1 ) V_36 - 1 ) + 1 ,
V_35 ) ) {
for ( V_37 = 0 ; V_37 < F_40 ( & V_34 ) ; V_37 ++ ) {
struct V_13 * V_13 = V_34 . V_40 [ V_37 ] ;
V_3 = V_35 [ V_37 ] ;
if ( V_3 > V_30 )
break;
if ( F_41 ( V_13 ) ) {
F_10 ( V_2 , V_3 ,
V_13 ) ;
continue;
}
if ( ! F_42 ( V_13 ) )
continue;
F_43 ( F_44 ( V_13 ) != V_3 ) ;
if ( F_61 ( V_13 ) ) {
F_45 ( V_13 ) ;
continue;
} else if ( F_27 ( V_13 ) ) {
V_3 += V_43 - 1 ;
V_37 += V_43 - 1 ;
if ( V_3 > V_30 ) {
F_45 ( V_13 ) ;
continue;
}
}
V_20 = F_32 ( V_13 ) ;
F_45 ( V_13 ) ;
if ( ! V_20 )
F_62 ( V_13 ) ;
V_42 += V_20 ;
}
F_46 ( & V_34 ) ;
F_47 ( & V_34 ) ;
F_48 () ;
V_3 ++ ;
}
return V_42 ;
}
static int
F_63 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
unsigned long V_44 ;
if ( V_13 -> V_2 != V_2 )
return 0 ;
if ( F_17 ( V_13 ) && ! F_22 ( V_13 , V_45 ) )
return 0 ;
F_64 ( & V_2 -> V_8 , V_44 ) ;
if ( F_34 ( V_13 ) )
goto V_46;
F_65 ( F_17 ( V_13 ) ) ;
F_66 ( V_13 , NULL ) ;
F_67 ( & V_2 -> V_8 , V_44 ) ;
if ( V_2 -> V_16 -> V_47 )
V_2 -> V_16 -> V_47 ( V_13 ) ;
F_53 ( V_13 ) ;
return 1 ;
V_46:
F_67 ( & V_2 -> V_8 , V_44 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
if ( ! F_34 ( V_13 ) )
return 0 ;
if ( V_13 -> V_2 != V_2 || V_2 -> V_16 -> V_48 == NULL )
return 0 ;
return V_2 -> V_16 -> V_48 ( V_13 ) ;
}
int F_69 ( struct V_1 * V_2 ,
T_1 V_29 , T_1 V_30 )
{
T_1 V_35 [ V_36 ] ;
struct V_33 V_34 ;
T_1 V_3 ;
int V_37 ;
int V_20 = 0 ;
int V_49 = 0 ;
int V_50 = 0 ;
if ( V_2 -> V_38 == 0 && V_2 -> V_12 == 0 )
goto V_39;
F_37 ( & V_34 , 0 ) ;
V_3 = V_29 ;
while ( V_3 <= V_30 && F_38 ( & V_34 , V_2 , V_3 ,
F_39 ( V_30 - V_3 , ( T_1 ) V_36 - 1 ) + 1 ,
V_35 ) ) {
for ( V_37 = 0 ; V_37 < F_40 ( & V_34 ) ; V_37 ++ ) {
struct V_13 * V_13 = V_34 . V_40 [ V_37 ] ;
V_3 = V_35 [ V_37 ] ;
if ( V_3 > V_30 )
break;
if ( F_41 ( V_13 ) ) {
if ( ! F_11 ( V_2 ,
V_3 , V_13 ) )
V_20 = - V_51 ;
continue;
}
F_54 ( V_13 ) ;
F_43 ( F_44 ( V_13 ) != V_3 ) ;
if ( V_13 -> V_2 != V_2 ) {
F_45 ( V_13 ) ;
continue;
}
F_50 ( V_13 ) ;
if ( F_28 ( V_13 ) ) {
if ( ! V_50 ) {
F_29 ( V_2 ,
( T_2 ) V_3 << V_23 ,
( T_2 ) ( 1 + V_30 - V_3 )
<< V_23 ,
0 ) ;
V_50 = 1 ;
} else {
F_29 ( V_2 ,
( T_2 ) V_3 << V_23 ,
V_19 , 0 ) ;
}
}
F_65 ( F_28 ( V_13 ) ) ;
V_49 = F_68 ( V_2 , V_13 ) ;
if ( V_49 == 0 ) {
if ( ! F_63 ( V_2 , V_13 ) )
V_49 = - V_51 ;
}
if ( V_49 < 0 )
V_20 = V_49 ;
F_45 ( V_13 ) ;
}
F_46 ( & V_34 ) ;
F_47 ( & V_34 ) ;
F_48 () ;
V_3 ++ ;
}
if ( F_8 ( V_2 ) ) {
F_29 ( V_2 , ( T_2 ) V_29 << V_23 ,
( T_2 ) ( V_30 - V_29 + 1 ) << V_23 , 0 ) ;
}
V_39:
F_55 ( V_2 ) ;
return V_20 ;
}
int F_70 ( struct V_1 * V_2 )
{
return F_69 ( V_2 , 0 , - 1 ) ;
}
void F_71 ( struct V_52 * V_52 , T_2 V_53 )
{
struct V_1 * V_2 = V_52 -> V_54 ;
T_2 V_55 = F_72 ( V_53 , V_19 ) ;
F_29 ( V_2 , V_55 , 0 , 1 ) ;
F_56 ( V_2 , V_53 ) ;
F_29 ( V_2 , V_55 , 0 , 1 ) ;
}
void F_73 ( struct V_52 * V_52 , T_2 V_53 )
{
T_2 V_56 = V_52 -> V_57 ;
F_74 ( V_52 , V_53 ) ;
if ( V_53 > V_56 )
F_75 ( V_52 , V_56 , V_53 ) ;
F_71 ( V_52 , V_53 ) ;
}
void F_75 ( struct V_52 * V_52 , T_2 V_58 , T_2 V_59 )
{
int V_60 = F_76 ( V_52 ) ;
T_2 V_61 ;
struct V_13 * V_13 ;
T_1 V_3 ;
F_43 ( V_59 > V_52 -> V_57 ) ;
if ( V_58 >= V_59 || V_60 == V_19 )
return;
V_61 = F_72 ( V_58 , V_60 ) ;
if ( V_59 <= V_61 || ! ( V_61 & ( V_19 - 1 ) ) )
return;
V_3 = V_58 >> V_23 ;
V_13 = F_49 ( V_52 -> V_54 , V_3 ) ;
if ( ! V_13 )
return;
if ( F_77 ( V_13 ) )
F_78 ( V_13 ) ;
F_45 ( V_13 ) ;
F_53 ( V_13 ) ;
}
void F_79 ( struct V_52 * V_52 , T_2 V_27 , T_2 V_28 )
{
struct V_1 * V_2 = V_52 -> V_54 ;
T_2 V_62 = F_72 ( V_27 , V_19 ) ;
T_2 V_63 = F_80 ( 1 + V_28 , V_19 ) - 1 ;
if ( ( V_64 ) V_63 > ( V_64 ) V_62 )
F_29 ( V_2 , V_62 ,
1 + V_63 - V_62 , 0 ) ;
F_36 ( V_2 , V_27 , V_28 ) ;
}
