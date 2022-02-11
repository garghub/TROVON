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
F_5 ( V_2 -> V_20 ) ;
F_6 ( V_21 ) ;
V_4 = F_7 ( V_2 ) ;
V_14 -> V_4 = V_4 ;
F_8 ( V_2 -> V_20 ) ;
if ( ! V_4 ) {
if ( F_9 () ) {
F_6 ( V_22 ) ;
break;
}
F_10 ( & V_14 -> V_19 ) ;
F_11 () ;
F_4 ( & V_14 -> V_19 ) ;
continue;
}
F_6 ( V_22 ) ;
V_14 -> V_23 ( V_14 , V_4 ) ;
} while ( 1 );
F_10 ( & V_14 -> V_19 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_24 ;
struct V_3 * V_4 ;
if ( ! V_14 ) {
while ( ( V_4 = F_7 ( V_2 ) ) != NULL ) {
V_4 -> V_7 |= V_25 ;
F_13 ( V_4 , - V_26 ) ;
}
return;
}
if ( ! V_14 -> V_4 )
F_14 ( V_14 -> V_27 ) ;
}
int F_15 ( struct V_13 * V_14 , struct V_28 * V_29 ,
T_1 * V_30 , const char * V_31 )
{
struct V_32 * V_33 = V_29 -> V_33 ;
T_2 V_34 = V_35 ;
int V_36 ;
if ( F_16 ( V_33 ) -> V_37 && * F_16 ( V_33 ) -> V_37 )
V_34 = * F_16 ( V_33 ) -> V_37 ;
V_14 -> V_29 = V_29 ;
V_14 -> V_15 = F_17 ( F_12 , V_30 ) ;
if ( ! V_14 -> V_15 )
return - V_38 ;
V_14 -> V_15 -> V_24 = V_14 ;
V_14 -> V_4 = NULL ;
F_18 ( V_14 -> V_15 , F_1 ) ;
F_19 ( V_39 , V_14 -> V_15 ) ;
if ( F_20 ( V_29 ) ) {
F_19 ( V_40 , V_14 -> V_15 ) ;
V_14 -> V_15 -> V_41 . V_42 = V_43 ;
if ( V_29 -> V_44 == 0 )
V_14 -> V_15 -> V_41 . V_45 = 1 ;
V_14 -> V_15 -> V_41 . V_46 = V_29 -> V_47 << 9 ;
if ( F_21 ( V_29 ) )
F_19 ( V_48 ,
V_14 -> V_15 ) ;
}
#ifdef F_22
if ( V_33 -> V_49 == 1 ) {
unsigned int V_50 ;
V_50 = V_51 ;
if ( V_50 > V_33 -> V_52 )
V_50 = V_33 -> V_52 ;
if ( V_50 > V_33 -> V_53 )
V_50 = V_33 -> V_53 ;
if ( V_50 > ( V_33 -> V_54 * 512 ) )
V_50 = V_33 -> V_54 * 512 ;
if ( V_50 > 512 ) {
V_14 -> V_55 = F_23 ( V_50 , V_56 ) ;
if ( ! V_14 -> V_55 ) {
F_24 ( V_57 L_2
L_3 ,
F_25 ( V_29 ) ) ;
}
}
if ( V_14 -> V_55 ) {
F_26 ( V_14 -> V_15 , V_58 ) ;
F_27 ( V_14 -> V_15 , V_50 / 512 ) ;
F_28 ( V_14 -> V_15 , V_50 / 512 ) ;
F_29 ( V_14 -> V_15 , V_50 ) ;
V_14 -> V_59 = F_23 ( sizeof( struct V_60 ) ,
V_56 ) ;
if ( ! V_14 -> V_59 ) {
V_36 = - V_38 ;
goto V_61;
}
F_30 ( V_14 -> V_59 , 1 ) ;
V_14 -> V_62 = F_23 ( sizeof( struct V_60 ) *
V_50 / 512 , V_56 ) ;
if ( ! V_14 -> V_62 ) {
V_36 = - V_38 ;
goto V_61;
}
F_30 ( V_14 -> V_62 , V_50 / 512 ) ;
}
}
#endif
if ( ! V_14 -> V_55 ) {
F_26 ( V_14 -> V_15 , V_34 ) ;
F_27 ( V_14 -> V_15 ,
F_31 ( V_33 -> V_54 , V_33 -> V_52 / 512 ) ) ;
F_28 ( V_14 -> V_15 , V_33 -> V_49 ) ;
F_29 ( V_14 -> V_15 , V_33 -> V_53 ) ;
V_14 -> V_59 = F_23 ( sizeof( struct V_60 ) *
V_33 -> V_49 , V_56 ) ;
if ( ! V_14 -> V_59 ) {
V_36 = - V_38 ;
goto V_61;
}
F_30 ( V_14 -> V_59 , V_33 -> V_49 ) ;
}
F_32 ( & V_14 -> V_19 , 1 ) ;
V_14 -> V_27 = F_33 ( F_3 , V_14 , L_4 ,
V_33 -> V_63 , V_31 ? V_31 : L_5 ) ;
if ( F_34 ( V_14 -> V_27 ) ) {
V_36 = F_35 ( V_14 -> V_27 ) ;
goto V_64;
}
return 0 ;
V_64:
if ( V_14 -> V_62 )
F_36 ( V_14 -> V_62 ) ;
V_14 -> V_62 = NULL ;
V_61:
if ( V_14 -> V_59 )
F_36 ( V_14 -> V_59 ) ;
V_14 -> V_59 = NULL ;
if ( V_14 -> V_55 )
F_36 ( V_14 -> V_55 ) ;
V_14 -> V_55 = NULL ;
F_37 ( V_14 -> V_15 ) ;
return V_36 ;
}
void F_38 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
unsigned long V_17 ;
F_39 ( V_14 ) ;
F_40 ( V_14 -> V_27 ) ;
F_41 ( V_2 -> V_20 , V_17 ) ;
V_2 -> V_24 = NULL ;
F_42 ( V_2 ) ;
F_43 ( V_2 -> V_20 , V_17 ) ;
if ( V_14 -> V_62 )
F_36 ( V_14 -> V_62 ) ;
V_14 -> V_62 = NULL ;
F_36 ( V_14 -> V_59 ) ;
V_14 -> V_59 = NULL ;
if ( V_14 -> V_55 )
F_36 ( V_14 -> V_55 ) ;
V_14 -> V_55 = NULL ;
V_14 -> V_29 = NULL ;
}
void F_44 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
unsigned long V_17 ;
if ( ! ( V_14 -> V_17 & V_65 ) ) {
V_14 -> V_17 |= V_65 ;
F_41 ( V_2 -> V_20 , V_17 ) ;
F_45 ( V_2 ) ;
F_43 ( V_2 -> V_20 , V_17 ) ;
F_4 ( & V_14 -> V_19 ) ;
}
}
void F_39 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
unsigned long V_17 ;
if ( V_14 -> V_17 & V_65 ) {
V_14 -> V_17 &= ~ V_65 ;
F_10 ( & V_14 -> V_19 ) ;
F_41 ( V_2 -> V_20 , V_17 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 -> V_20 , V_17 ) ;
}
}
unsigned int F_46 ( struct V_13 * V_14 )
{
unsigned int V_66 ;
T_3 V_67 ;
struct V_60 * V_59 ;
int V_68 ;
if ( ! V_14 -> V_55 )
return F_47 ( V_14 -> V_15 , V_14 -> V_4 , V_14 -> V_59 ) ;
F_48 ( ! V_14 -> V_62 ) ;
V_66 = F_47 ( V_14 -> V_15 , V_14 -> V_4 , V_14 -> V_62 ) ;
V_14 -> V_69 = V_66 ;
V_67 = 0 ;
F_49 (mq->bounce_sg, sg, sg_len, i)
V_67 += V_59 -> V_70 ;
F_50 ( V_14 -> V_59 , V_14 -> V_55 , V_67 ) ;
return 1 ;
}
void F_51 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_55 )
return;
if ( F_52 ( V_14 -> V_4 ) != V_71 )
return;
F_53 ( V_14 -> V_62 , V_14 -> V_69 ,
V_14 -> V_55 , V_14 -> V_59 [ 0 ] . V_70 ) ;
}
void F_54 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_55 )
return;
if ( F_52 ( V_14 -> V_4 ) != V_72 )
return;
F_55 ( V_14 -> V_62 , V_14 -> V_69 ,
V_14 -> V_55 , V_14 -> V_59 [ 0 ] . V_70 ) ;
}
