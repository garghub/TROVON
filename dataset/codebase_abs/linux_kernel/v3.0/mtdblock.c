static void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = ( T_1 * ) V_2 -> V_4 ;
F_2 ( V_3 ) ;
}
static int F_3 ( struct V_5 * V_6 , unsigned long V_7 ,
int V_8 , const char * V_9 )
{
struct V_1 V_10 ;
F_4 ( V_11 , V_12 ) ;
T_1 V_3 ;
T_2 V_13 ;
int V_14 ;
F_5 ( & V_3 ) ;
V_10 . V_6 = V_6 ;
V_10 . V_15 = F_1 ;
V_10 . V_16 = V_7 ;
V_10 . V_8 = V_8 ;
V_10 . V_4 = ( V_17 ) & V_3 ;
F_6 ( V_18 ) ;
F_7 ( & V_3 , & V_11 ) ;
V_14 = V_6 -> V_10 ( V_6 , & V_10 ) ;
if ( V_14 ) {
F_6 ( V_19 ) ;
F_8 ( & V_3 , & V_11 ) ;
F_9 ( V_20 L_1
L_2 ,
V_7 , V_8 , V_6 -> V_21 ) ;
return V_14 ;
}
F_10 () ;
F_8 ( & V_3 , & V_11 ) ;
V_14 = V_6 -> V_22 ( V_6 , V_7 , V_8 , & V_13 , V_9 ) ;
if ( V_14 )
return V_14 ;
if ( V_13 != V_8 )
return - V_23 ;
return 0 ;
}
static int F_11 ( struct V_24 * V_25 )
{
struct V_5 * V_6 = V_25 -> V_26 . V_6 ;
int V_14 ;
if ( V_25 -> V_27 != V_28 )
return 0 ;
F_12 ( V_29 , L_3
L_4 , V_6 -> V_21 ,
V_25 -> V_30 , V_25 -> V_31 ) ;
V_14 = F_3 ( V_6 , V_25 -> V_30 ,
V_25 -> V_31 , V_25 -> V_32 ) ;
if ( V_14 )
return V_14 ;
V_25 -> V_27 = V_33 ;
return 0 ;
}
static int F_13 ( struct V_24 * V_25 , unsigned long V_7 ,
int V_8 , const char * V_9 )
{
struct V_5 * V_6 = V_25 -> V_26 . V_6 ;
unsigned int V_34 = V_25 -> V_31 ;
T_2 V_13 ;
int V_14 ;
F_12 ( V_29 , L_5 ,
V_6 -> V_21 , V_7 , V_8 ) ;
if ( ! V_34 )
return V_6 -> V_22 ( V_6 , V_7 , V_8 , & V_13 , V_9 ) ;
while ( V_8 > 0 ) {
unsigned long V_35 = ( V_7 / V_34 ) * V_34 ;
unsigned int V_36 = V_7 - V_35 ;
unsigned int V_37 = V_34 - V_36 ;
if( V_37 > V_8 )
V_37 = V_8 ;
if ( V_37 == V_34 ) {
V_14 = F_3 ( V_6 , V_7 , V_37 , V_9 ) ;
if ( V_14 )
return V_14 ;
} else {
if ( V_25 -> V_27 == V_28 &&
V_25 -> V_30 != V_35 ) {
V_14 = F_11 ( V_25 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_25 -> V_27 == V_33 ||
V_25 -> V_30 != V_35 ) {
V_25 -> V_27 = V_33 ;
V_14 = V_6 -> V_38 ( V_6 , V_35 , V_34 ,
& V_13 , V_25 -> V_32 ) ;
if ( V_14 )
return V_14 ;
if ( V_13 != V_34 )
return - V_23 ;
V_25 -> V_30 = V_35 ;
V_25 -> V_31 = V_34 ;
V_25 -> V_27 = V_39 ;
}
memcpy ( V_25 -> V_32 + V_36 , V_9 , V_37 ) ;
V_25 -> V_27 = V_28 ;
}
V_9 += V_37 ;
V_7 += V_37 ;
V_8 -= V_37 ;
}
return 0 ;
}
static int F_14 ( struct V_24 * V_25 , unsigned long V_7 ,
int V_8 , char * V_9 )
{
struct V_5 * V_6 = V_25 -> V_26 . V_6 ;
unsigned int V_34 = V_25 -> V_31 ;
T_2 V_13 ;
int V_14 ;
F_12 ( V_29 , L_6 ,
V_6 -> V_21 , V_7 , V_8 ) ;
if ( ! V_34 )
return V_6 -> V_38 ( V_6 , V_7 , V_8 , & V_13 , V_9 ) ;
while ( V_8 > 0 ) {
unsigned long V_35 = ( V_7 / V_34 ) * V_34 ;
unsigned int V_36 = V_7 - V_35 ;
unsigned int V_37 = V_34 - V_36 ;
if ( V_37 > V_8 )
V_37 = V_8 ;
if ( V_25 -> V_27 != V_33 &&
V_25 -> V_30 == V_35 ) {
memcpy ( V_9 , V_25 -> V_32 + V_36 , V_37 ) ;
} else {
V_14 = V_6 -> V_38 ( V_6 , V_7 , V_37 , & V_13 , V_9 ) ;
if ( V_14 )
return V_14 ;
if ( V_13 != V_37 )
return - V_23 ;
}
V_9 += V_37 ;
V_7 += V_37 ;
V_8 -= V_37 ;
}
return 0 ;
}
static int F_15 ( struct V_40 * V_41 ,
unsigned long V_42 , char * V_9 )
{
struct V_24 * V_25 = F_16 ( V_41 , struct V_24 , V_26 ) ;
return F_14 ( V_25 , V_42 << 9 , 512 , V_9 ) ;
}
static int F_17 ( struct V_40 * V_41 ,
unsigned long V_42 , char * V_9 )
{
struct V_24 * V_25 = F_16 ( V_41 , struct V_24 , V_26 ) ;
if ( F_18 ( ! V_25 -> V_32 && V_25 -> V_31 ) ) {
V_25 -> V_32 = F_19 ( V_25 -> V_26 . V_6 -> V_43 ) ;
if ( ! V_25 -> V_32 )
return - V_44 ;
}
return F_13 ( V_25 , V_42 << 9 , 512 , V_9 ) ;
}
static int F_20 ( struct V_40 * V_26 )
{
struct V_24 * V_25 = F_16 ( V_26 , struct V_24 , V_26 ) ;
F_12 ( V_45 , L_7 ) ;
F_21 ( & V_46 ) ;
if ( V_25 -> V_47 ) {
V_25 -> V_47 ++ ;
F_22 ( & V_46 ) ;
return 0 ;
}
V_25 -> V_47 = 1 ;
F_23 ( & V_25 -> V_48 ) ;
V_25 -> V_27 = V_33 ;
if ( ! ( V_26 -> V_6 -> V_49 & V_50 ) && V_26 -> V_6 -> V_43 ) {
V_25 -> V_31 = V_26 -> V_6 -> V_43 ;
V_25 -> V_32 = NULL ;
}
F_22 ( & V_46 ) ;
F_12 ( V_45 , L_8 ) ;
return 0 ;
}
static int F_24 ( struct V_40 * V_26 )
{
struct V_24 * V_25 = F_16 ( V_26 , struct V_24 , V_26 ) ;
F_12 ( V_45 , L_9 ) ;
F_21 ( & V_46 ) ;
F_21 ( & V_25 -> V_48 ) ;
F_11 ( V_25 ) ;
F_22 ( & V_25 -> V_48 ) ;
if ( ! -- V_25 -> V_47 ) {
if ( V_26 -> V_6 -> V_51 )
V_26 -> V_6 -> V_51 ( V_26 -> V_6 ) ;
F_25 ( V_25 -> V_32 ) ;
}
F_22 ( & V_46 ) ;
F_12 ( V_45 , L_8 ) ;
return 0 ;
}
static int F_26 ( struct V_40 * V_41 )
{
struct V_24 * V_25 = F_16 ( V_41 , struct V_24 , V_26 ) ;
F_21 ( & V_25 -> V_48 ) ;
F_11 ( V_25 ) ;
F_22 ( & V_25 -> V_48 ) ;
if ( V_41 -> V_6 -> V_51 )
V_41 -> V_6 -> V_51 ( V_41 -> V_6 ) ;
return 0 ;
}
static void F_27 ( struct V_52 * V_53 , struct V_5 * V_6 )
{
struct V_24 * V_41 = F_28 ( sizeof( * V_41 ) , V_54 ) ;
if ( ! V_41 )
return;
V_41 -> V_26 . V_6 = V_6 ;
V_41 -> V_26 . V_55 = V_6 -> V_56 ;
V_41 -> V_26 . V_37 = V_6 -> V_37 >> 9 ;
V_41 -> V_26 . V_53 = V_53 ;
if ( ! ( V_6 -> V_49 & V_57 ) )
V_41 -> V_26 . V_58 = 1 ;
if ( F_29 ( & V_41 -> V_26 ) )
F_30 ( V_41 ) ;
}
static void F_31 ( struct V_40 * V_41 )
{
F_32 ( V_41 ) ;
}
static int T_3 F_33 ( void )
{
F_23 ( & V_46 ) ;
return F_34 ( & V_59 ) ;
}
static void T_4 F_35 ( void )
{
F_36 ( & V_59 ) ;
}
