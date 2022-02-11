static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 , V_6 ;
T_2 V_7 ;
int V_8 ;
V_7 = F_2 ( V_2 -> V_9 ) ;
V_5 = F_3 ( V_2 -> V_9 ) + V_10 ;
V_8 = F_4 ( V_4 , V_7 , V_5 , & V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( F_5 ( V_11 , V_6 ) != V_12 ) {
F_6 ( V_4 , L_1 ) ;
return - V_13 ;
}
V_2 -> V_14 . V_15 = F_5 ( V_16 , V_6 ) ;
V_2 -> V_14 . V_17 = F_5 ( V_18 , V_6 ) ;
if ( V_2 -> V_14 . V_15 != V_19 || V_2 -> V_14 . V_17 < V_20 ) {
F_6 ( V_4 , L_2 ,
V_2 -> V_14 . V_15 , V_2 -> V_14 . V_17 ) ;
return - V_21 ;
}
if ( V_6 & V_22 ) {
F_6 ( V_4 , L_3 ) ;
return - V_23 ;
}
return 0 ;
}
struct V_1 * F_7 ( struct V_3 * V_4 )
{
struct V_24 * V_9 ;
struct V_1 * V_2 ;
int V_8 ;
V_9 = F_8 ( V_4 , V_25 ) ;
if ( F_9 ( V_9 ) )
return ( void * ) V_9 ;
V_2 = F_10 ( sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 ) {
F_11 ( V_9 ) ;
return F_12 ( - V_27 ) ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_9 = V_9 ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 ) {
F_13 ( V_2 ) ;
return F_12 ( V_8 ) ;
}
return V_2 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_9 ) ;
F_14 ( V_2 ) ;
}
T_3 F_15 ( struct V_1 * V_2 )
{
return V_2 -> V_14 . V_15 ;
}
T_3 F_16 ( struct V_1 * V_2 )
{
return V_2 -> V_14 . V_17 ;
}
static int
F_17 ( struct V_3 * V_4 , T_1 * V_6 ,
T_2 V_7 , T_1 V_28 , T_1 V_29 , T_1 V_30 )
{
const unsigned long V_31 = V_32 + 30 * V_33 ;
int V_8 ;
for (; ; ) {
const unsigned long V_34 = V_32 ;
V_8 = F_4 ( V_4 , V_7 , V_28 , V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( * V_6 & V_29 ) == V_30 )
return 0 ;
V_8 = F_18 ( 100 ) ;
if ( V_8 )
return V_8 ;
if ( F_19 ( V_34 , V_31 ) )
return - V_35 ;
}
}
static int F_20 ( struct V_1 * V_2 , T_3 V_36 , T_2 V_37 ,
T_2 V_38 , T_1 V_39 )
{
T_1 V_6 , V_40 , V_41 , V_5 , V_42 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_7 ;
int V_8 ;
V_7 = F_2 ( V_2 -> V_9 ) ;
V_40 = F_3 ( V_2 -> V_9 ) ;
V_5 = V_40 + V_10 ;
V_42 = V_40 + V_43 ;
V_41 = V_40 + V_44 ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( ! F_21 ( V_45 , V_38 >> 8 ) ||
! F_21 ( V_46 , V_39 ) ) {
F_6 ( V_4 , L_4 ,
V_38 , V_39 ) ;
return - V_21 ;
}
V_8 = F_22 ( V_4 , V_7 , V_41 ,
F_23 ( V_45 , V_38 >> 8 ) |
F_23 ( V_46 , V_39 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_22 ( V_4 , V_7 , V_42 ,
F_23 ( V_47 , V_37 ) |
F_23 ( V_48 , V_36 ) |
F_23 ( V_49 , 1 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_17 ( V_4 , & V_6 ,
V_7 , V_42 , V_49 , 0 ) ;
if ( V_8 ) {
F_6 ( V_4 , L_5 ,
V_8 , V_36 ) ;
return V_8 ;
}
V_8 = F_17 ( V_4 , & V_6 ,
V_7 , V_5 , V_22 , 0 ) ;
if ( V_8 ) {
F_6 ( V_4 , L_6 ,
V_8 , V_36 ) ;
return V_8 ;
}
V_8 = F_5 ( V_50 , V_6 ) ;
if ( V_8 ) {
F_24 ( V_4 , L_7 ,
- V_8 , V_36 ) ;
return - V_8 ;
}
V_8 = F_4 ( V_4 , V_7 , V_42 , & V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_5 ( V_47 , V_6 ) ;
}
static int F_25 ( struct V_1 * V_51 , T_3 V_36 , T_2 V_37 ,
const void * V_52 , unsigned int V_53 ,
void * V_54 , unsigned int V_55 )
{
struct V_3 * V_4 = V_51 -> V_4 ;
unsigned int V_56 ;
T_1 V_6 , V_57 ;
int V_58 , V_8 ;
T_2 V_59 ;
if ( V_51 -> V_14 . V_17 < 13 ) {
F_6 ( V_4 , L_8 ,
V_36 , V_51 -> V_14 . V_15 , V_51 -> V_14 . V_17 ) ;
return - V_60 ;
}
V_8 = F_4 ( V_4 , F_2 ( V_51 -> V_9 ) ,
F_3 ( V_51 -> V_9 ) +
V_61 ,
& V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
V_56 = F_26 ( V_53 , V_55 ) ;
if ( F_5 ( V_62 , V_6 ) * V_63 < V_56 ) {
F_6 ( V_4 , L_9 ,
V_36 , F_5 ( V_62 , V_6 ) * V_63 ,
V_56 ) ;
return - V_21 ;
}
V_8 = F_4 ( V_4 , F_2 ( V_51 -> V_9 ) ,
F_3 ( V_51 -> V_9 ) +
V_64 ,
& V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
V_59 = F_5 ( V_45 , V_6 ) << 8 ;
V_57 = F_5 ( V_46 , V_6 ) ;
if ( V_52 && V_53 ) {
V_8 = F_27 ( V_4 , V_59 , V_57 , V_52 , V_53 ) ;
if ( V_8 < 0 )
return V_8 ;
}
V_58 = F_20 ( V_51 , V_36 , V_37 , V_59 , V_57 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_54 && V_55 ) {
V_8 = F_28 ( V_4 , V_59 , V_57 , V_54 , V_55 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return V_58 ;
}
int F_29 ( struct V_1 * V_2 )
{
const unsigned long V_31 = V_32 + 30 * V_33 ;
int V_8 ;
F_30 ( V_2 -> V_4 , L_10 ) ;
for (; ; ) {
const unsigned long V_34 = V_32 ;
V_8 = F_20 ( V_2 , V_65 , 0 , 0 , 0 ) ;
if ( V_8 != - V_66 )
break;
V_8 = F_18 ( 100 ) ;
if ( V_8 )
break;
if ( F_19 ( V_34 , V_31 ) ) {
V_8 = - V_35 ;
break;
}
}
if ( V_8 )
F_6 ( V_2 -> V_4 , L_11 , V_8 ) ;
return V_8 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_20 ( V_2 , V_67 , 0 , 0 , 0 ) ;
F_32 ( V_2 -> V_4 ) ;
return V_8 ;
}
int F_33 ( struct V_1 * V_2 , const struct V_68 * V_69 )
{
return F_25 ( V_2 , V_70 , V_69 -> V_71 , V_69 -> V_72 ,
V_69 -> V_71 , NULL , 0 ) ;
}
int F_34 ( struct V_1 * V_2 , void * V_73 , unsigned int V_71 )
{
return F_25 ( V_2 , V_74 , V_71 , NULL , 0 ,
V_73 , V_71 ) ;
}
int F_35 ( struct V_1 * V_2 ,
const void * V_73 , unsigned int V_71 )
{
return F_25 ( V_2 , V_75 , V_71 , V_73 , V_71 ,
NULL , 0 ) ;
}
