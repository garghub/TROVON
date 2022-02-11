static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 < 1000000 )
V_2 -> V_4 . V_5 = ( V_2 -> V_3 * 1000 ) / V_2 -> V_6 ;
else {
unsigned int V_7 ;
V_7 = V_2 -> V_3 % V_2 -> V_6 ;
V_7 = ( V_7 * 1000 ) / V_2 -> V_6 ;
V_2 -> V_4 . V_5 = ( V_2 -> V_3 / V_2 -> V_6 ) * 1000 ;
V_2 -> V_4 . V_5 += V_7 ;
}
if ( V_2 -> V_4 . V_5 <= 0 )
V_2 -> V_4 . V_5 = 1 ;
F_2 ( & V_2 -> V_4 , 0 ) ;
}
struct V_1 * F_3 ( void )
{
struct V_1 * V_2 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
return NULL ;
F_5 ( & V_2 -> V_9 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
return V_2 ;
}
void F_8 ( struct V_1 * * V_2 )
{
struct V_1 * V_10 = * V_2 ;
* V_2 = NULL ;
if ( V_10 == NULL ) {
F_9 ( L_1 ) ;
return;
}
V_10 -> V_11 = 0 ;
F_10 ( V_10 ) ;
F_7 ( V_10 ) ;
F_11 ( V_10 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_6 = 96 ;
V_2 -> V_3 = 500000 ;
F_1 ( V_2 ) ;
V_2 -> V_11 = 0 ;
V_2 -> type = V_12 ;
V_2 -> V_13 . V_14 = V_15 ;
V_2 -> V_13 . V_16 = V_17 ;
V_2 -> V_13 . V_18 = V_19 ;
V_2 -> V_13 . V_20 = V_21 ;
V_2 -> V_13 . V_22 = V_23 ;
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = V_2 -> V_27 = V_28 ;
}
void F_7 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
F_12 ( & V_2 -> V_9 , V_29 ) ;
V_2 -> V_30 . V_31 = 0 ;
V_2 -> V_30 . V_32 = 0 ;
V_2 -> V_4 . V_33 = 0 ;
V_2 -> V_4 . V_34 = 0 ;
F_13 ( & V_2 -> V_9 , V_29 ) ;
}
static void F_14 ( struct V_35 * V_36 ,
unsigned long V_5 ,
unsigned long V_37 )
{
unsigned long V_29 ;
struct V_38 * V_39 = V_36 -> V_40 ;
struct V_1 * V_2 ;
if ( V_39 == NULL )
return;
V_2 = V_39 -> V_41 ;
if ( V_2 == NULL )
return;
if ( ! V_2 -> V_11 )
return;
V_5 *= V_37 ;
if ( V_2 -> V_26 != V_2 -> V_27 ) {
V_5 = ( V_5 >> 16 ) * V_2 -> V_26 +
( ( ( V_5 & 0xffff ) * V_2 -> V_26 ) >> 16 ) ;
}
F_12 ( & V_2 -> V_9 , V_29 ) ;
F_15 ( & V_2 -> V_30 , V_5 ) ;
F_2 ( & V_2 -> V_4 , V_5 ) ;
F_16 ( & V_2 -> V_42 ) ;
F_13 ( & V_2 -> V_9 , V_29 ) ;
F_17 ( V_39 , 1 , 0 ) ;
}
int F_18 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_29 ;
if ( F_19 ( ! V_2 ) )
return - V_43 ;
if ( V_3 <= 0 )
return - V_43 ;
F_12 ( & V_2 -> V_9 , V_29 ) ;
if ( ( unsigned int ) V_3 != V_2 -> V_3 ) {
V_2 -> V_3 = V_3 ;
F_1 ( V_2 ) ;
}
F_13 ( & V_2 -> V_9 , V_29 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , int V_6 )
{
unsigned long V_29 ;
if ( F_19 ( ! V_2 ) )
return - V_43 ;
if ( V_6 <= 0 )
return - V_43 ;
F_12 ( & V_2 -> V_9 , V_29 ) ;
if ( V_2 -> V_11 && ( V_6 != V_2 -> V_6 ) ) {
F_13 ( & V_2 -> V_9 , V_29 ) ;
F_9 ( L_2 ) ;
return - V_44 ;
}
V_2 -> V_6 = V_6 ;
F_1 ( V_2 ) ;
F_13 ( & V_2 -> V_9 , V_29 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 ,
T_1 V_45 )
{
unsigned long V_29 ;
if ( F_19 ( ! V_2 ) )
return - V_43 ;
F_12 ( & V_2 -> V_9 , V_29 ) ;
V_2 -> V_4 . V_33 = V_45 ;
V_2 -> V_4 . V_34 = 0 ;
F_13 ( & V_2 -> V_9 , V_29 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 ,
T_2 V_45 )
{
unsigned long V_29 ;
if ( F_19 ( ! V_2 ) )
return - V_43 ;
F_23 ( & V_45 ) ;
F_12 ( & V_2 -> V_9 , V_29 ) ;
V_2 -> V_30 = V_45 ;
F_13 ( & V_2 -> V_9 , V_29 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , unsigned int V_26 ,
unsigned int V_46 )
{
unsigned long V_29 ;
if ( F_19 ( ! V_2 ) )
return - V_43 ;
if ( V_46 != V_28 ) {
F_9 ( L_3 , V_46 ) ;
return - V_43 ;
}
F_12 ( & V_2 -> V_9 , V_29 ) ;
V_2 -> V_26 = V_26 ;
F_13 ( & V_2 -> V_9 , V_29 ) ;
return 0 ;
}
int F_25 ( struct V_38 * V_39 )
{
struct V_35 * V_10 ;
struct V_1 * V_2 ;
char V_47 [ 32 ] ;
int V_48 ;
V_2 = V_39 -> V_41 ;
if ( F_19 ( ! V_2 ) )
return - V_43 ;
if ( V_2 -> V_36 )
return - V_44 ;
sprintf ( V_47 , L_4 , V_39 -> V_49 ) ;
if ( V_2 -> type != V_12 )
return - V_43 ;
if ( V_2 -> V_13 . V_14 != V_50 )
V_2 -> V_13 . V_16 = V_51 ;
V_48 = F_26 ( & V_10 , V_47 , & V_2 -> V_13 , V_39 -> V_49 ) ;
if ( V_48 < 0 && V_2 -> V_13 . V_14 != V_50 ) {
if ( V_2 -> V_13 . V_14 != V_52 ||
V_2 -> V_13 . V_20 != V_53 ) {
struct V_54 V_55 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_14 = V_52 ;
V_55 . V_16 = V_51 ;
V_55 . V_18 = - 1 ;
V_55 . V_20 = V_53 ;
V_48 = F_26 ( & V_10 , V_47 , & V_55 , V_39 -> V_49 ) ;
}
}
if ( V_48 < 0 ) {
F_27 ( L_5 , V_48 ) ;
return V_48 ;
}
V_10 -> V_56 = F_14 ;
V_10 -> V_40 = V_39 ;
V_10 -> V_29 |= V_57 ;
V_2 -> V_36 = V_10 ;
return 0 ;
}
int F_28 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
V_2 = V_39 -> V_41 ;
if ( F_19 ( ! V_2 ) )
return - V_43 ;
if ( V_2 -> V_36 ) {
F_29 ( V_2 -> V_36 ) ;
F_30 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_36 )
return - V_43 ;
if ( ! V_2 -> V_11 )
return 0 ;
V_2 -> V_11 = 0 ;
F_31 ( V_2 -> V_36 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_58 * V_10 ;
unsigned long V_59 ;
V_10 = V_2 -> V_36 -> V_41 ;
if ( F_19 ( ! V_10 ) )
return - V_43 ;
V_59 = V_2 -> V_24 ;
if ( ! V_59 )
V_59 = V_60 ;
else if ( V_59 < V_61 )
V_59 = V_61 ;
else if ( V_59 > V_62 )
V_59 = V_62 ;
V_2 -> V_37 = 1 ;
if ( ! ( V_10 -> V_63 . V_29 & V_64 ) ) {
unsigned long V_65 = V_10 -> V_63 . V_5 ;
if ( ! V_65 && V_10 -> V_63 . V_66 )
V_65 = V_10 -> V_63 . V_66 ( V_10 ) ;
if ( V_65 ) {
V_2 -> V_37 = ( unsigned int ) ( 1000000000uL / ( V_65 * V_59 ) ) ;
if ( ! V_2 -> V_37 )
V_2 -> V_37 = 1 ;
}
}
V_2 -> V_67 = 1 ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_36 )
return - V_43 ;
if ( V_2 -> V_11 )
F_10 ( V_2 ) ;
F_7 ( V_2 ) ;
if ( F_32 ( V_2 ) < 0 )
return - V_43 ;
F_34 ( V_2 -> V_36 , V_2 -> V_37 ) ;
V_2 -> V_11 = 1 ;
F_16 ( & V_2 -> V_42 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_36 )
return - V_43 ;
if ( V_2 -> V_11 )
return - V_44 ;
if ( ! V_2 -> V_67 ) {
F_7 ( V_2 ) ;
if ( F_32 ( V_2 ) < 0 )
return - V_43 ;
}
F_34 ( V_2 -> V_36 , V_2 -> V_37 ) ;
V_2 -> V_11 = 1 ;
F_16 ( & V_2 -> V_42 ) ;
return 0 ;
}
T_2 F_36 ( struct V_1 * V_2 )
{
T_2 V_30 ;
V_30 = V_2 -> V_30 ;
if ( V_2 -> V_11 ) {
struct V_68 V_69 ;
int V_70 ;
F_16 ( & V_69 ) ;
V_70 = ( int ) ( V_69 . V_71 - V_2 -> V_42 . V_71 ) ;
if ( V_70 < 0 ) {
V_30 . V_32 += ( 1000000 + V_70 ) * 1000 ;
V_30 . V_31 += V_69 . V_31 - V_2 -> V_42 . V_31 - 1 ;
} else {
V_30 . V_32 += V_70 * 1000 ;
V_30 . V_31 += V_69 . V_31 - V_2 -> V_42 . V_31 ;
}
F_23 ( & V_30 ) ;
}
return V_30 ;
}
T_1 F_37 ( struct V_1 * V_2 )
{
return V_2 -> V_4 . V_33 ;
}
void F_38 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
int V_76 ;
struct V_38 * V_39 ;
struct V_1 * V_2 ;
struct V_35 * V_77 ;
unsigned long V_5 ;
for ( V_76 = 0 ; V_76 < V_78 ; V_76 ++ ) {
V_39 = F_39 ( V_76 ) ;
if ( V_39 == NULL )
continue;
if ( ( V_2 = V_39 -> V_41 ) == NULL ||
( V_77 = V_2 -> V_36 ) == NULL ) {
F_40 ( V_39 ) ;
continue;
}
F_41 ( V_75 , L_6 , V_39 -> V_49 , V_77 -> V_41 -> V_79 ) ;
V_5 = F_42 ( V_77 ) * V_2 -> V_37 ;
F_41 ( V_75 , L_7 , V_5 / 1000000000 , V_5 % 1000000000 ) ;
F_41 ( V_75 , L_8 , V_2 -> V_26 , V_2 -> V_27 ) ;
F_40 ( V_39 ) ;
}
}
