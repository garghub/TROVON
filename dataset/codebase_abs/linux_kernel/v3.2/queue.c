static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_5 != V_6 && ! ( V_4 -> V_7 & V_8 ) ) {
F_2 ( V_4 , L_1 ) ;
return V_9 ;
}
V_4 -> V_7 |= V_10 ;
return V_11 ;
}
static int F_3 ( void * V_12 )
{
struct V_13 * V_14 = V_12 ;
struct V_1 * V_2 = V_14 -> V_15 ;
V_16 -> V_17 |= V_18 ;
F_4 ( & V_14 -> V_19 ) ;
do {
struct V_3 * V_4 = NULL ;
struct V_20 * V_21 ;
F_5 ( V_2 -> V_22 ) ;
F_6 ( V_23 ) ;
V_4 = F_7 ( V_2 ) ;
V_14 -> V_24 -> V_4 = V_4 ;
F_8 ( V_2 -> V_22 ) ;
if ( V_4 || V_14 -> V_25 -> V_4 ) {
F_6 ( V_26 ) ;
V_14 -> V_27 ( V_14 , V_4 ) ;
} else {
if ( F_9 () ) {
F_6 ( V_26 ) ;
break;
}
F_10 ( & V_14 -> V_19 ) ;
F_11 () ;
F_4 ( & V_14 -> V_19 ) ;
}
V_14 -> V_25 -> V_28 . V_29 . V_30 = NULL ;
V_14 -> V_25 -> V_4 = NULL ;
V_21 = V_14 -> V_25 ;
V_14 -> V_25 = V_14 -> V_24 ;
V_14 -> V_24 = V_21 ;
} while ( 1 );
F_10 ( & V_14 -> V_19 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_31 ;
struct V_3 * V_4 ;
if ( ! V_14 ) {
while ( ( V_4 = F_7 ( V_2 ) ) != NULL ) {
V_4 -> V_7 |= V_32 ;
F_13 ( V_4 , - V_33 ) ;
}
return;
}
if ( ! V_14 -> V_24 -> V_4 && ! V_14 -> V_25 -> V_4 )
F_14 ( V_14 -> V_34 ) ;
}
static struct V_35 * F_15 ( int V_36 , int * V_37 )
{
struct V_35 * V_38 ;
V_38 = F_16 ( sizeof( struct V_35 ) * V_36 , V_39 ) ;
if ( ! V_38 )
* V_37 = - V_40 ;
else {
* V_37 = 0 ;
F_17 ( V_38 , V_36 ) ;
}
return V_38 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
unsigned V_43 ;
V_43 = F_19 ( V_42 ) ;
if ( ! V_43 )
return;
F_20 ( V_44 , V_2 ) ;
V_2 -> V_45 . V_46 = V_43 ;
if ( V_42 -> V_47 == 0 )
V_2 -> V_45 . V_48 = 1 ;
V_2 -> V_45 . V_49 = V_42 -> V_50 << 9 ;
if ( V_42 -> V_50 > V_43 )
V_2 -> V_45 . V_49 = 0 ;
if ( F_21 ( V_42 ) || F_22 ( V_42 ) )
F_20 ( V_51 , V_2 ) ;
}
int F_23 ( struct V_13 * V_14 , struct V_41 * V_42 ,
T_1 * V_52 , const char * V_53 )
{
struct V_54 * V_55 = V_42 -> V_55 ;
T_2 V_56 = V_57 ;
int V_58 ;
struct V_20 * V_24 = & V_14 -> V_59 [ 0 ] ;
struct V_20 * V_25 = & V_14 -> V_59 [ 1 ] ;
if ( F_24 ( V_55 ) -> V_60 && * F_24 ( V_55 ) -> V_60 )
V_56 = * F_24 ( V_55 ) -> V_60 ;
V_14 -> V_42 = V_42 ;
V_14 -> V_15 = F_25 ( F_12 , V_52 ) ;
if ( ! V_14 -> V_15 )
return - V_40 ;
memset ( & V_14 -> V_24 , 0 , sizeof( V_14 -> V_24 ) ) ;
memset ( & V_14 -> V_25 , 0 , sizeof( V_14 -> V_25 ) ) ;
V_14 -> V_24 = V_24 ;
V_14 -> V_25 = V_25 ;
V_14 -> V_15 -> V_31 = V_14 ;
F_26 ( V_14 -> V_15 , F_1 ) ;
F_20 ( V_61 , V_14 -> V_15 ) ;
if ( F_27 ( V_42 ) )
F_18 ( V_14 -> V_15 , V_42 ) ;
#ifdef F_28
if ( V_55 -> V_62 == 1 ) {
unsigned int V_63 ;
V_63 = V_64 ;
if ( V_63 > V_55 -> V_65 )
V_63 = V_55 -> V_65 ;
if ( V_63 > V_55 -> V_66 )
V_63 = V_55 -> V_66 ;
if ( V_63 > ( V_55 -> V_67 * 512 ) )
V_63 = V_55 -> V_67 * 512 ;
if ( V_63 > 512 ) {
V_24 -> V_68 = F_16 ( V_63 , V_39 ) ;
if ( ! V_24 -> V_68 ) {
F_29 ( L_2
L_3 ,
F_30 ( V_42 ) ) ;
}
V_25 -> V_68 = F_16 ( V_63 , V_39 ) ;
if ( ! V_25 -> V_68 ) {
F_29 ( L_2
L_4 ,
F_30 ( V_42 ) ) ;
F_31 ( V_24 -> V_68 ) ;
V_24 -> V_68 = NULL ;
}
}
if ( V_24 -> V_68 && V_25 -> V_68 ) {
F_32 ( V_14 -> V_15 , V_69 ) ;
F_33 ( V_14 -> V_15 , V_63 / 512 ) ;
F_34 ( V_14 -> V_15 , V_63 / 512 ) ;
F_35 ( V_14 -> V_15 , V_63 ) ;
V_24 -> V_38 = F_15 ( 1 , & V_58 ) ;
if ( V_58 )
goto V_70;
V_24 -> V_71 =
F_15 ( V_63 / 512 , & V_58 ) ;
if ( V_58 )
goto V_70;
V_25 -> V_38 = F_15 ( 1 , & V_58 ) ;
if ( V_58 )
goto V_70;
V_25 -> V_71 =
F_15 ( V_63 / 512 , & V_58 ) ;
if ( V_58 )
goto V_70;
}
}
#endif
if ( ! V_24 -> V_68 && ! V_25 -> V_68 ) {
F_32 ( V_14 -> V_15 , V_56 ) ;
F_33 ( V_14 -> V_15 ,
F_36 ( V_55 -> V_67 , V_55 -> V_65 / 512 ) ) ;
F_34 ( V_14 -> V_15 , V_55 -> V_62 ) ;
F_35 ( V_14 -> V_15 , V_55 -> V_66 ) ;
V_24 -> V_38 = F_15 ( V_55 -> V_62 , & V_58 ) ;
if ( V_58 )
goto V_70;
V_25 -> V_38 = F_15 ( V_55 -> V_62 , & V_58 ) ;
if ( V_58 )
goto V_70;
}
F_37 ( & V_14 -> V_19 , 1 ) ;
V_14 -> V_34 = F_38 ( F_3 , V_14 , L_5 ,
V_55 -> V_72 , V_53 ? V_53 : L_6 ) ;
if ( F_39 ( V_14 -> V_34 ) ) {
V_58 = F_40 ( V_14 -> V_34 ) ;
goto V_73;
}
return 0 ;
V_73:
F_31 ( V_24 -> V_71 ) ;
V_24 -> V_71 = NULL ;
F_31 ( V_25 -> V_71 ) ;
V_25 -> V_71 = NULL ;
V_70:
F_31 ( V_24 -> V_38 ) ;
V_24 -> V_38 = NULL ;
F_31 ( V_24 -> V_68 ) ;
V_24 -> V_68 = NULL ;
F_31 ( V_25 -> V_38 ) ;
V_25 -> V_38 = NULL ;
F_31 ( V_25 -> V_68 ) ;
V_25 -> V_68 = NULL ;
F_41 ( V_14 -> V_15 ) ;
return V_58 ;
}
void F_42 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
unsigned long V_17 ;
struct V_20 * V_24 = V_14 -> V_24 ;
struct V_20 * V_25 = V_14 -> V_25 ;
F_43 ( V_14 ) ;
F_44 ( V_14 -> V_34 ) ;
F_45 ( V_2 -> V_22 , V_17 ) ;
V_2 -> V_31 = NULL ;
F_46 ( V_2 ) ;
F_47 ( V_2 -> V_22 , V_17 ) ;
F_31 ( V_24 -> V_71 ) ;
V_24 -> V_71 = NULL ;
F_31 ( V_24 -> V_38 ) ;
V_24 -> V_38 = NULL ;
F_31 ( V_24 -> V_68 ) ;
V_24 -> V_68 = NULL ;
F_31 ( V_25 -> V_71 ) ;
V_25 -> V_71 = NULL ;
F_31 ( V_25 -> V_38 ) ;
V_25 -> V_38 = NULL ;
F_31 ( V_25 -> V_68 ) ;
V_25 -> V_68 = NULL ;
V_14 -> V_42 = NULL ;
}
void F_48 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
unsigned long V_17 ;
if ( ! ( V_14 -> V_17 & V_74 ) ) {
V_14 -> V_17 |= V_74 ;
F_45 ( V_2 -> V_22 , V_17 ) ;
F_49 ( V_2 ) ;
F_47 ( V_2 -> V_22 , V_17 ) ;
F_4 ( & V_14 -> V_19 ) ;
}
}
void F_43 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
unsigned long V_17 ;
if ( V_14 -> V_17 & V_74 ) {
V_14 -> V_17 &= ~ V_74 ;
F_10 ( & V_14 -> V_19 ) ;
F_45 ( V_2 -> V_22 , V_17 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 -> V_22 , V_17 ) ;
}
}
unsigned int F_50 ( struct V_13 * V_14 , struct V_20 * V_59 )
{
unsigned int V_36 ;
T_3 V_75 ;
struct V_35 * V_38 ;
int V_76 ;
if ( ! V_59 -> V_68 )
return F_51 ( V_14 -> V_15 , V_59 -> V_4 , V_59 -> V_38 ) ;
F_52 ( ! V_59 -> V_71 ) ;
V_36 = F_51 ( V_14 -> V_15 , V_59 -> V_4 , V_59 -> V_71 ) ;
V_59 -> V_77 = V_36 ;
V_75 = 0 ;
F_53 (mqrq->bounce_sg, sg, sg_len, i)
V_75 += V_38 -> V_78 ;
F_54 ( V_59 -> V_38 , V_59 -> V_68 , V_75 ) ;
return 1 ;
}
void F_55 ( struct V_20 * V_59 )
{
if ( ! V_59 -> V_68 )
return;
if ( F_56 ( V_59 -> V_4 ) != V_79 )
return;
F_57 ( V_59 -> V_71 , V_59 -> V_77 ,
V_59 -> V_68 , V_59 -> V_38 [ 0 ] . V_78 ) ;
}
void F_58 ( struct V_20 * V_59 )
{
if ( ! V_59 -> V_68 )
return;
if ( F_56 ( V_59 -> V_4 ) != V_80 )
return;
F_59 ( V_59 -> V_71 , V_59 -> V_77 ,
V_59 -> V_68 , V_59 -> V_38 [ 0 ] . V_78 ) ;
}
