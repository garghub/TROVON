static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_4 -> V_8 != V_9 && ! ( V_4 -> V_10 & V_11 ) ) {
F_2 ( V_4 , L_1 ) ;
return V_12 ;
}
if ( V_6 && F_3 ( V_6 -> V_13 ) )
return V_12 ;
V_4 -> V_10 |= V_14 ;
return V_15 ;
}
static int F_4 ( void * V_16 )
{
struct V_5 * V_6 = V_16 ;
struct V_1 * V_2 = V_6 -> V_17 ;
V_18 -> V_19 |= V_20 ;
F_5 ( & V_6 -> V_21 ) ;
do {
struct V_3 * V_4 = NULL ;
struct V_22 * V_23 ;
F_6 ( V_2 -> V_24 ) ;
F_7 ( V_25 ) ;
V_4 = F_8 ( V_2 ) ;
V_6 -> V_26 -> V_4 = V_4 ;
F_9 ( V_2 -> V_24 ) ;
if ( V_4 || V_6 -> V_27 -> V_4 ) {
F_7 ( V_28 ) ;
V_6 -> V_29 ( V_6 , V_4 ) ;
} else {
if ( F_10 () ) {
F_7 ( V_28 ) ;
break;
}
F_11 ( & V_6 -> V_21 ) ;
F_12 () ;
F_5 ( & V_6 -> V_21 ) ;
}
V_6 -> V_27 -> V_30 . V_31 . V_32 = NULL ;
V_6 -> V_27 -> V_4 = NULL ;
V_23 = V_6 -> V_27 ;
V_6 -> V_27 = V_6 -> V_26 ;
V_6 -> V_26 = V_23 ;
} while ( 1 );
F_11 ( & V_6 -> V_21 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_4 ;
if ( ! V_6 ) {
while ( ( V_4 = F_8 ( V_2 ) ) != NULL ) {
V_4 -> V_10 |= V_33 ;
F_14 ( V_4 , - V_34 ) ;
}
return;
}
if ( ! V_6 -> V_26 -> V_4 && ! V_6 -> V_27 -> V_4 )
F_15 ( V_6 -> V_35 ) ;
}
static struct V_36 * F_16 ( int V_37 , int * V_38 )
{
struct V_36 * V_39 ;
V_39 = F_17 ( sizeof( struct V_36 ) * V_37 , V_40 ) ;
if ( ! V_39 )
* V_38 = - V_41 ;
else {
* V_38 = 0 ;
F_18 ( V_39 , V_37 ) ;
}
return V_39 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_42 * V_13 )
{
unsigned V_43 ;
V_43 = F_20 ( V_13 ) ;
if ( ! V_43 )
return;
F_21 ( V_44 , V_2 ) ;
V_2 -> V_45 . V_46 = V_43 ;
if ( V_13 -> V_47 == 0 )
V_2 -> V_45 . V_48 = 1 ;
V_2 -> V_45 . V_49 = V_13 -> V_50 << 9 ;
if ( V_13 -> V_50 > V_43 )
V_2 -> V_45 . V_49 = 0 ;
if ( F_22 ( V_13 ) || F_23 ( V_13 ) )
F_21 ( V_51 , V_2 ) ;
}
int F_24 ( struct V_5 * V_6 , struct V_42 * V_13 ,
T_1 * V_52 , const char * V_53 )
{
struct V_54 * V_55 = V_13 -> V_55 ;
T_2 V_56 = V_57 ;
int V_58 ;
struct V_22 * V_26 = & V_6 -> V_59 [ 0 ] ;
struct V_22 * V_27 = & V_6 -> V_59 [ 1 ] ;
if ( F_25 ( V_55 ) -> V_60 && * F_25 ( V_55 ) -> V_60 )
V_56 = * F_25 ( V_55 ) -> V_60 ;
V_6 -> V_13 = V_13 ;
V_6 -> V_17 = F_26 ( F_13 , V_52 ) ;
if ( ! V_6 -> V_17 )
return - V_41 ;
memset ( & V_6 -> V_26 , 0 , sizeof( V_6 -> V_26 ) ) ;
memset ( & V_6 -> V_27 , 0 , sizeof( V_6 -> V_27 ) ) ;
V_6 -> V_26 = V_26 ;
V_6 -> V_27 = V_27 ;
V_6 -> V_17 -> V_7 = V_6 ;
F_27 ( V_6 -> V_17 , F_1 ) ;
F_21 ( V_61 , V_6 -> V_17 ) ;
if ( F_28 ( V_13 ) )
F_19 ( V_6 -> V_17 , V_13 ) ;
#ifdef F_29
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
V_26 -> V_68 = F_17 ( V_63 , V_40 ) ;
if ( ! V_26 -> V_68 ) {
F_30 ( L_2
L_3 ,
F_31 ( V_13 ) ) ;
}
V_27 -> V_68 = F_17 ( V_63 , V_40 ) ;
if ( ! V_27 -> V_68 ) {
F_30 ( L_2
L_4 ,
F_31 ( V_13 ) ) ;
F_32 ( V_26 -> V_68 ) ;
V_26 -> V_68 = NULL ;
}
}
if ( V_26 -> V_68 && V_27 -> V_68 ) {
F_33 ( V_6 -> V_17 , V_69 ) ;
F_34 ( V_6 -> V_17 , V_63 / 512 ) ;
F_35 ( V_6 -> V_17 , V_63 / 512 ) ;
F_36 ( V_6 -> V_17 , V_63 ) ;
V_26 -> V_39 = F_16 ( 1 , & V_58 ) ;
if ( V_58 )
goto V_70;
V_26 -> V_71 =
F_16 ( V_63 / 512 , & V_58 ) ;
if ( V_58 )
goto V_70;
V_27 -> V_39 = F_16 ( 1 , & V_58 ) ;
if ( V_58 )
goto V_70;
V_27 -> V_71 =
F_16 ( V_63 / 512 , & V_58 ) ;
if ( V_58 )
goto V_70;
}
}
#endif
if ( ! V_26 -> V_68 && ! V_27 -> V_68 ) {
F_33 ( V_6 -> V_17 , V_56 ) ;
F_34 ( V_6 -> V_17 ,
F_37 ( V_55 -> V_67 , V_55 -> V_65 / 512 ) ) ;
F_35 ( V_6 -> V_17 , V_55 -> V_62 ) ;
F_36 ( V_6 -> V_17 , V_55 -> V_66 ) ;
V_26 -> V_39 = F_16 ( V_55 -> V_62 , & V_58 ) ;
if ( V_58 )
goto V_70;
V_27 -> V_39 = F_16 ( V_55 -> V_62 , & V_58 ) ;
if ( V_58 )
goto V_70;
}
F_38 ( & V_6 -> V_21 , 1 ) ;
V_6 -> V_35 = F_39 ( F_4 , V_6 , L_5 ,
V_55 -> V_72 , V_53 ? V_53 : L_6 ) ;
if ( F_40 ( V_6 -> V_35 ) ) {
V_58 = F_41 ( V_6 -> V_35 ) ;
goto V_73;
}
return 0 ;
V_73:
F_32 ( V_26 -> V_71 ) ;
V_26 -> V_71 = NULL ;
F_32 ( V_27 -> V_71 ) ;
V_27 -> V_71 = NULL ;
V_70:
F_32 ( V_26 -> V_39 ) ;
V_26 -> V_39 = NULL ;
F_32 ( V_26 -> V_68 ) ;
V_26 -> V_68 = NULL ;
F_32 ( V_27 -> V_39 ) ;
V_27 -> V_39 = NULL ;
F_32 ( V_27 -> V_68 ) ;
V_27 -> V_68 = NULL ;
F_42 ( V_6 -> V_17 ) ;
return V_58 ;
}
void F_43 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_17 ;
unsigned long V_19 ;
struct V_22 * V_26 = V_6 -> V_26 ;
struct V_22 * V_27 = V_6 -> V_27 ;
F_44 ( V_6 ) ;
F_45 ( V_6 -> V_35 ) ;
F_46 ( V_2 -> V_24 , V_19 ) ;
V_2 -> V_7 = NULL ;
F_47 ( V_2 ) ;
F_48 ( V_2 -> V_24 , V_19 ) ;
F_32 ( V_26 -> V_71 ) ;
V_26 -> V_71 = NULL ;
F_32 ( V_26 -> V_39 ) ;
V_26 -> V_39 = NULL ;
F_32 ( V_26 -> V_68 ) ;
V_26 -> V_68 = NULL ;
F_32 ( V_27 -> V_71 ) ;
V_27 -> V_71 = NULL ;
F_32 ( V_27 -> V_39 ) ;
V_27 -> V_39 = NULL ;
F_32 ( V_27 -> V_68 ) ;
V_27 -> V_68 = NULL ;
V_6 -> V_13 = NULL ;
}
void F_49 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_17 ;
unsigned long V_19 ;
if ( ! ( V_6 -> V_19 & V_74 ) ) {
V_6 -> V_19 |= V_74 ;
F_46 ( V_2 -> V_24 , V_19 ) ;
F_50 ( V_2 ) ;
F_48 ( V_2 -> V_24 , V_19 ) ;
F_5 ( & V_6 -> V_21 ) ;
}
}
void F_44 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_17 ;
unsigned long V_19 ;
if ( V_6 -> V_19 & V_74 ) {
V_6 -> V_19 &= ~ V_74 ;
F_11 ( & V_6 -> V_21 ) ;
F_46 ( V_2 -> V_24 , V_19 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 -> V_24 , V_19 ) ;
}
}
unsigned int F_51 ( struct V_5 * V_6 , struct V_22 * V_59 )
{
unsigned int V_37 ;
T_3 V_75 ;
struct V_36 * V_39 ;
int V_76 ;
if ( ! V_59 -> V_68 )
return F_52 ( V_6 -> V_17 , V_59 -> V_4 , V_59 -> V_39 ) ;
F_53 ( ! V_59 -> V_71 ) ;
V_37 = F_52 ( V_6 -> V_17 , V_59 -> V_4 , V_59 -> V_71 ) ;
V_59 -> V_77 = V_37 ;
V_75 = 0 ;
F_54 (mqrq->bounce_sg, sg, sg_len, i)
V_75 += V_39 -> V_78 ;
F_55 ( V_59 -> V_39 , V_59 -> V_68 , V_75 ) ;
return 1 ;
}
void F_56 ( struct V_22 * V_59 )
{
if ( ! V_59 -> V_68 )
return;
if ( F_57 ( V_59 -> V_4 ) != V_79 )
return;
F_58 ( V_59 -> V_71 , V_59 -> V_77 ,
V_59 -> V_68 , V_59 -> V_39 [ 0 ] . V_78 ) ;
}
void F_59 ( struct V_22 * V_59 )
{
if ( ! V_59 -> V_68 )
return;
if ( F_57 ( V_59 -> V_4 ) != V_80 )
return;
F_60 ( V_59 -> V_71 , V_59 -> V_77 ,
V_59 -> V_68 , V_59 -> V_39 [ 0 ] . V_78 ) ;
}
