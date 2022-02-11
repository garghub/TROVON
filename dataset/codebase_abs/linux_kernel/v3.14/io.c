static unsigned F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 ) ;
struct V_5 V_6 ;
struct V_7 V_8 ;
unsigned V_9 = 0 , V_10 = 0 ;
if ( V_1 -> V_11 & V_12 )
return F_3 ( F_4 ( V_1 ) , V_3 -> V_13 . V_14 ) ;
F_5 (bv, bio, iter) {
struct V_15 V_16 = {
. V_4 = V_1 -> V_4 ,
. V_17 = V_1 -> V_18 . V_17 ,
. V_19 = V_9 << 9 ,
. V_11 = V_1 -> V_11 ,
} ;
if ( V_10 == F_6 ( unsigned , V_20 ,
F_7 ( V_3 ) ) )
break;
if ( V_3 -> V_21 &&
V_3 -> V_21 ( V_3 , & V_16 , & V_6 ) < ( int ) V_6 . V_22 )
break;
V_10 ++ ;
V_9 += V_6 . V_22 >> 9 ;
}
V_9 = F_3 ( V_9 , F_8 ( V_3 ) ) ;
F_9 ( ! V_9 ) ;
V_9 = F_10 ( int , V_9 , F_11 ( V_1 ) . V_22 >> 9 ) ;
return V_9 ;
}
static void F_12 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_13 ( V_24 , struct V_25 , V_24 ) ;
V_26 -> V_1 -> V_27 = V_26 -> V_27 ;
V_26 -> V_1 -> V_28 = V_26 -> V_28 ;
F_14 ( V_26 -> V_1 , 0 ) ;
F_15 ( & V_26 -> V_24 ) ;
F_16 ( V_26 , V_26 -> V_29 -> V_25 ) ;
}
static void F_17 ( struct V_1 * V_1 , int error )
{
struct V_23 * V_24 = V_1 -> V_28 ;
struct V_25 * V_26 = F_13 ( V_24 , struct V_25 , V_24 ) ;
if ( error )
F_18 ( V_30 , & V_26 -> V_1 -> V_31 ) ;
F_19 ( V_1 ) ;
F_20 ( V_24 ) ;
}
void F_21 ( struct V_1 * V_1 , struct V_32 * V_29 )
{
struct V_25 * V_26 ;
struct V_1 * V_33 ;
if ( ! F_22 ( V_1 ) && ! ( V_1 -> V_11 & V_12 ) )
goto V_34;
if ( F_4 ( V_1 ) <= F_1 ( V_1 ) )
goto V_34;
V_26 = F_23 ( V_29 -> V_25 , V_35 ) ;
F_24 ( & V_26 -> V_24 , NULL ) ;
V_26 -> V_1 = V_1 ;
V_26 -> V_29 = V_29 ;
V_26 -> V_27 = V_1 -> V_27 ;
V_26 -> V_28 = V_1 -> V_28 ;
F_25 ( V_1 ) ;
do {
V_33 = F_26 ( V_1 , F_1 ( V_1 ) ,
V_35 , V_26 -> V_29 -> V_36 ) ;
V_33 -> V_27 = F_17 ;
V_33 -> V_28 = & V_26 -> V_24 ;
F_27 ( & V_26 -> V_24 ) ;
F_28 ( V_33 ) ;
} while ( V_33 != V_1 );
F_29 ( & V_26 -> V_24 , F_12 , NULL ) ;
V_34:
F_28 ( V_1 ) ;
}
void F_30 ( struct V_1 * V_1 , struct V_37 * V_38 )
{
struct V_39 * V_40 = F_13 ( V_1 , struct V_39 , V_1 ) ;
F_16 ( V_40 , V_38 -> V_41 ) ;
}
struct V_1 * F_31 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_23 ( V_38 -> V_41 , V_35 ) ;
struct V_1 * V_1 = & V_40 -> V_1 ;
F_32 ( V_1 ) ;
V_1 -> V_31 |= V_42 << V_43 ;
V_1 -> V_44 = F_33 ( V_38 ) ;
V_1 -> V_45 = V_1 -> V_46 ;
return V_1 ;
}
void F_34 ( struct V_1 * V_1 , struct V_37 * V_38 )
{
struct V_39 * V_40 = F_13 ( V_1 , struct V_39 , V_1 ) ;
V_1 -> V_18 . V_17 = F_35 ( & V_40 -> V_47 , 0 ) ;
V_1 -> V_4 = F_36 ( V_38 , & V_40 -> V_47 , 0 ) -> V_48 ;
V_40 -> V_49 = F_37 () ;
F_38 ( V_1 , V_1 -> V_28 , F_36 ( V_38 , & V_40 -> V_47 , 0 ) ) ;
}
void F_39 ( struct V_1 * V_1 , struct V_37 * V_38 ,
struct V_50 * V_51 , unsigned V_52 )
{
struct V_39 * V_40 = F_13 ( V_1 , struct V_39 , V_1 ) ;
F_40 ( & V_40 -> V_47 , V_51 , V_52 ) ;
F_34 ( V_1 , V_38 ) ;
}
void F_41 ( struct V_53 * V_54 , int error , const char * V_55 )
{
if ( V_54 -> V_56 -> V_57 ) {
unsigned V_58 = F_42 ( & V_54 -> V_59 ) ;
while ( V_58 > V_54 -> V_56 -> V_57 ) {
unsigned V_60 ;
unsigned V_61 = V_58 ;
unsigned V_62 = V_58 - V_54 -> V_56 -> V_57 ;
V_58 = F_43 ( & V_54 -> V_59 , V_61 , V_62 ) ;
if ( V_58 == V_61 ) {
V_58 = V_62 ;
V_60 = F_44 ( & V_54 -> V_63 ) ;
do {
V_61 = V_60 ;
V_62 = ( ( V_64 ) V_60 * 127 ) / 128 ;
V_60 = F_43 ( & V_54 -> V_63 ,
V_61 , V_62 ) ;
} while ( V_61 != V_60 );
}
}
}
if ( error ) {
char V_65 [ V_66 ] ;
unsigned V_60 = F_45 ( 1 << V_67 ,
& V_54 -> V_63 ) ;
V_60 >>= V_67 ;
if ( V_60 < V_54 -> V_56 -> V_68 )
F_46 ( L_1 ,
F_47 ( V_54 -> V_48 , V_65 ) , V_55 ) ;
else
F_48 ( V_54 -> V_56 ,
L_2 ,
F_47 ( V_54 -> V_48 , V_65 ) , V_55 ) ;
}
}
void F_49 ( struct V_37 * V_38 , struct V_1 * V_1 ,
int error , const char * V_55 )
{
struct V_39 * V_40 = F_13 ( V_1 , struct V_39 , V_1 ) ;
struct V_53 * V_54 = F_36 ( V_38 , & V_40 -> V_47 , 0 ) ;
unsigned V_69 = V_1 -> V_11 & V_70
? V_38 -> V_71
: V_38 -> V_72 ;
if ( V_69 ) {
unsigned V_73 = F_37 () ;
int V_74 = V_73 - V_40 -> V_49 ;
int V_75 = F_44 ( & V_38 -> V_75 ) ;
if ( V_74 > ( int ) V_69 ) {
int V_76 = V_74 / 1024 ;
V_38 -> V_77 = V_73 ;
V_76 = F_3 ( V_76 , V_78 + V_75 ) ;
F_50 ( V_76 , & V_38 -> V_75 ) ;
} else if ( V_75 < 0 )
F_51 ( & V_38 -> V_75 ) ;
}
F_41 ( V_54 , error , V_55 ) ;
}
void F_52 ( struct V_37 * V_38 , struct V_1 * V_1 ,
int error , const char * V_55 )
{
struct V_23 * V_24 = V_1 -> V_28 ;
F_49 ( V_38 , V_1 , error , V_55 ) ;
F_19 ( V_1 ) ;
F_20 ( V_24 ) ;
}
