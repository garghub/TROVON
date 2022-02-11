static void F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( 1 , V_2 -> V_7 + V_8 ) ;
F_3 ( V_3 , V_2 -> V_7 + V_9 ) ;
F_3 ( V_4 , V_2 -> V_7 + V_10 ) ;
F_3 ( 1 , V_2 -> V_7 + V_11 ) ;
F_3 ( 0 , V_2 -> V_7 + V_8 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
static T_1 F_5 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
F_6 ( V_2 -> V_14 , 1 , V_15 ) ;
return V_16 ;
}
static int F_7 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
unsigned long V_21 , V_22 ;
unsigned long long V_23 ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
do {
V_22 = F_9 ( V_2 -> V_7 + V_24 ) ;
V_21 = F_9 ( V_2 -> V_7 + V_25 ) ;
} while ( F_9 ( V_2 -> V_7 + V_24 ) != V_22 );
F_4 ( & V_2 -> V_6 , V_5 ) ;
V_23 = ( ( unsigned long long ) V_22 << 32 ) | V_21 ;
F_10 ( V_23 , V_2 -> V_26 ) ;
F_11 ( V_23 , V_20 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
unsigned long long V_23 ;
unsigned long V_27 , V_5 ;
int V_28 ;
V_28 = F_13 ( V_20 , & V_27 ) ;
if ( V_28 )
return V_28 ;
V_23 = ( unsigned long long ) V_27 * V_2 -> V_26 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_23 >> 32 , V_2 -> V_7 + V_24 ) ;
F_3 ( V_23 , V_2 -> V_7 + V_25 ) ;
F_3 ( 1 , V_2 -> V_7 + V_29 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_17 * V_18 , struct V_30 * V_31 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
memcpy ( V_31 , & V_2 -> V_32 , sizeof( struct V_30 ) ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
return 0 ;
}
static int F_15 ( struct V_17 * V_18 , unsigned int V_33 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
if ( V_33 && ! V_2 -> V_34 ) {
F_16 ( V_2 -> V_35 ) ;
V_2 -> V_34 = true ;
} else if ( ! V_33 && V_2 -> V_34 ) {
F_17 ( V_2 -> V_35 ) ;
V_2 -> V_34 = false ;
}
return 0 ;
}
static int F_18 ( struct V_17 * V_18 , struct V_30 * V_36 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
struct V_19 V_37 ;
unsigned long V_38 ;
unsigned long V_39 ;
unsigned long long V_40 ;
F_7 ( V_18 , & V_37 ) ;
F_13 ( & V_37 , & V_38 ) ;
F_13 ( & V_36 -> time , & V_39 ) ;
if ( V_38 > V_39 )
return - V_41 ;
memcpy ( & V_2 -> V_32 , V_36 , sizeof( struct V_30 ) ) ;
V_39 -= V_38 ;
V_40 = ( unsigned long long ) V_39 * V_2 -> V_26 ;
F_1 ( V_2 , V_40 >> 32 , V_40 ) ;
F_15 ( V_18 , V_36 -> V_33 ) ;
return 0 ;
}
static int F_19 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_18 . V_46 ;
struct V_1 * V_2 ;
struct V_47 * V_48 ;
struct V_19 V_49 ;
T_2 V_50 ;
int V_28 = 0 ;
V_28 = F_20 ( V_45 , L_1 , & V_50 ) ;
if ( V_28 ) {
F_21 ( & V_43 -> V_18 , L_2 ) ;
return - V_41 ;
}
if ( V_50 != V_51 )
return - V_52 ;
V_2 = F_22 ( & V_43 -> V_18 , sizeof( struct V_1 ) , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
F_23 ( & V_2 -> V_6 ) ;
V_48 = F_24 ( V_43 , V_55 , 0 ) ;
V_2 -> V_7 = F_25 ( & V_43 -> V_18 , V_48 ) ;
if ( F_26 ( V_2 -> V_7 ) )
return F_27 ( V_2 -> V_7 ) ;
V_2 -> V_35 = F_28 ( V_45 , 0 ) ;
if ( ! V_2 -> V_35 ) {
F_21 ( & V_43 -> V_18 , L_3 ) ;
return - V_41 ;
}
V_28 = F_29 ( & V_43 -> V_18 , V_2 -> V_35 , F_5 , 0 ,
V_43 -> V_56 , V_2 ) ;
if ( V_28 ) {
F_21 ( & V_43 -> V_18 , L_4 , V_2 -> V_35 ) ;
return V_28 ;
}
F_30 ( V_2 -> V_35 ) ;
F_17 ( V_2 -> V_35 ) ;
V_2 -> V_57 = F_31 ( & V_43 -> V_18 , NULL ) ;
if ( F_26 ( V_2 -> V_57 ) ) {
F_21 ( & V_43 -> V_18 , L_5 ) ;
return F_27 ( V_2 -> V_57 ) ;
}
F_32 ( V_2 -> V_57 ) ;
V_2 -> V_26 = F_33 ( V_2 -> V_57 ) ;
if ( ! V_2 -> V_26 ) {
F_21 ( & V_43 -> V_18 , L_6 ) ;
return - V_41 ;
}
F_34 ( & V_43 -> V_18 , 1 ) ;
F_35 ( V_43 , V_2 ) ;
F_7 ( & V_43 -> V_18 , & V_49 ) ;
if ( V_49 . V_58 >= ( 2038 - 1900 ) ) {
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_58 = 100 ;
V_49 . V_59 = 1 ;
F_12 ( & V_43 -> V_18 , & V_49 ) ;
}
V_2 -> V_14 = F_36 ( L_7 , & V_43 -> V_18 ,
& V_60 , V_61 ) ;
if ( F_26 ( V_2 -> V_14 ) ) {
F_37 ( V_2 -> V_57 ) ;
return F_27 ( V_2 -> V_14 ) ;
}
return 0 ;
}
static int F_38 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_39 ( V_43 ) ;
if ( F_40 ( V_2 -> V_14 ) )
F_41 ( V_2 -> V_14 ) ;
return 0 ;
}
static int F_42 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
if ( F_43 ( V_18 ) )
return 0 ;
F_3 ( 1 , V_2 -> V_7 + V_8 ) ;
F_3 ( 0 , V_2 -> V_7 + V_11 ) ;
F_3 ( 0 , V_2 -> V_7 + V_8 ) ;
return 0 ;
}
static int F_44 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
F_45 ( V_2 -> V_14 , 0 ) ;
memset ( & V_2 -> V_32 , 0 , sizeof( struct V_30 ) ) ;
F_3 ( 0 , V_2 -> V_7 + V_9 ) ;
F_3 ( 0 , V_2 -> V_7 + V_10 ) ;
F_3 ( 1 , V_2 -> V_7 + V_8 ) ;
F_3 ( 1 , V_2 -> V_7 + V_11 ) ;
F_3 ( 0 , V_2 -> V_7 + V_8 ) ;
return 0 ;
}
