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
V_14 = F_8 ( V_6 , & V_10 ) ;
if ( V_14 ) {
F_6 ( V_19 ) ;
F_9 ( & V_3 , & V_11 ) ;
F_10 ( V_20 L_1
L_2 ,
V_7 , V_8 , V_6 -> V_21 ) ;
return V_14 ;
}
F_11 () ;
F_9 ( & V_3 , & V_11 ) ;
V_14 = F_12 ( V_6 , V_7 , V_8 , & V_13 , V_9 ) ;
if ( V_14 )
return V_14 ;
if ( V_13 != V_8 )
return - V_22 ;
return 0 ;
}
static int F_13 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = V_24 -> V_25 . V_6 ;
int V_14 ;
if ( V_24 -> V_26 != V_27 )
return 0 ;
F_14 ( L_3
L_4 , V_6 -> V_21 ,
V_24 -> V_28 , V_24 -> V_29 ) ;
V_14 = F_3 ( V_6 , V_24 -> V_28 ,
V_24 -> V_29 , V_24 -> V_30 ) ;
if ( V_14 )
return V_14 ;
V_24 -> V_26 = V_31 ;
return 0 ;
}
static int F_15 ( struct V_23 * V_24 , unsigned long V_7 ,
int V_8 , const char * V_9 )
{
struct V_5 * V_6 = V_24 -> V_25 . V_6 ;
unsigned int V_32 = V_24 -> V_29 ;
T_2 V_13 ;
int V_14 ;
F_14 ( L_5 ,
V_6 -> V_21 , V_7 , V_8 ) ;
if ( ! V_32 )
return F_12 ( V_6 , V_7 , V_8 , & V_13 , V_9 ) ;
while ( V_8 > 0 ) {
unsigned long V_33 = ( V_7 / V_32 ) * V_32 ;
unsigned int V_34 = V_7 - V_33 ;
unsigned int V_35 = V_32 - V_34 ;
if( V_35 > V_8 )
V_35 = V_8 ;
if ( V_35 == V_32 ) {
V_14 = F_3 ( V_6 , V_7 , V_35 , V_9 ) ;
if ( V_14 )
return V_14 ;
} else {
if ( V_24 -> V_26 == V_27 &&
V_24 -> V_28 != V_33 ) {
V_14 = F_13 ( V_24 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_24 -> V_26 == V_31 ||
V_24 -> V_28 != V_33 ) {
V_24 -> V_26 = V_31 ;
V_14 = F_16 ( V_6 , V_33 , V_32 ,
& V_13 , V_24 -> V_30 ) ;
if ( V_14 )
return V_14 ;
if ( V_13 != V_32 )
return - V_22 ;
V_24 -> V_28 = V_33 ;
V_24 -> V_29 = V_32 ;
V_24 -> V_26 = V_36 ;
}
memcpy ( V_24 -> V_30 + V_34 , V_9 , V_35 ) ;
V_24 -> V_26 = V_27 ;
}
V_9 += V_35 ;
V_7 += V_35 ;
V_8 -= V_35 ;
}
return 0 ;
}
static int F_17 ( struct V_23 * V_24 , unsigned long V_7 ,
int V_8 , char * V_9 )
{
struct V_5 * V_6 = V_24 -> V_25 . V_6 ;
unsigned int V_32 = V_24 -> V_29 ;
T_2 V_13 ;
int V_14 ;
F_14 ( L_6 ,
V_6 -> V_21 , V_7 , V_8 ) ;
if ( ! V_32 )
return F_16 ( V_6 , V_7 , V_8 , & V_13 , V_9 ) ;
while ( V_8 > 0 ) {
unsigned long V_33 = ( V_7 / V_32 ) * V_32 ;
unsigned int V_34 = V_7 - V_33 ;
unsigned int V_35 = V_32 - V_34 ;
if ( V_35 > V_8 )
V_35 = V_8 ;
if ( V_24 -> V_26 != V_31 &&
V_24 -> V_28 == V_33 ) {
memcpy ( V_9 , V_24 -> V_30 + V_34 , V_35 ) ;
} else {
V_14 = F_16 ( V_6 , V_7 , V_35 , & V_13 , V_9 ) ;
if ( V_14 )
return V_14 ;
if ( V_13 != V_35 )
return - V_22 ;
}
V_9 += V_35 ;
V_7 += V_35 ;
V_8 -= V_35 ;
}
return 0 ;
}
static int F_18 ( struct V_37 * V_38 ,
unsigned long V_39 , char * V_9 )
{
struct V_23 * V_24 = F_19 ( V_38 , struct V_23 , V_25 ) ;
return F_17 ( V_24 , V_39 << 9 , 512 , V_9 ) ;
}
static int F_20 ( struct V_37 * V_38 ,
unsigned long V_39 , char * V_9 )
{
struct V_23 * V_24 = F_19 ( V_38 , struct V_23 , V_25 ) ;
if ( F_21 ( ! V_24 -> V_30 && V_24 -> V_29 ) ) {
V_24 -> V_30 = F_22 ( V_24 -> V_25 . V_6 -> V_40 ) ;
if ( ! V_24 -> V_30 )
return - V_41 ;
}
return F_15 ( V_24 , V_39 << 9 , 512 , V_9 ) ;
}
static int F_23 ( struct V_37 * V_25 )
{
struct V_23 * V_24 = F_19 ( V_25 , struct V_23 , V_25 ) ;
F_14 ( L_7 ) ;
F_24 ( & V_42 ) ;
if ( V_24 -> V_43 ) {
V_24 -> V_43 ++ ;
F_25 ( & V_42 ) ;
return 0 ;
}
V_24 -> V_43 = 1 ;
F_26 ( & V_24 -> V_44 ) ;
V_24 -> V_26 = V_31 ;
if ( ! ( V_25 -> V_6 -> V_45 & V_46 ) && V_25 -> V_6 -> V_40 ) {
V_24 -> V_29 = V_25 -> V_6 -> V_40 ;
V_24 -> V_30 = NULL ;
}
F_25 ( & V_42 ) ;
F_14 ( L_8 ) ;
return 0 ;
}
static void F_27 ( struct V_37 * V_25 )
{
struct V_23 * V_24 = F_19 ( V_25 , struct V_23 , V_25 ) ;
F_14 ( L_9 ) ;
F_24 ( & V_42 ) ;
F_24 ( & V_24 -> V_44 ) ;
F_13 ( V_24 ) ;
F_25 ( & V_24 -> V_44 ) ;
if ( ! -- V_24 -> V_43 ) {
if ( V_25 -> V_47 & V_48 )
F_28 ( V_25 -> V_6 ) ;
F_29 ( V_24 -> V_30 ) ;
}
F_25 ( & V_42 ) ;
F_14 ( L_8 ) ;
}
static int F_30 ( struct V_37 * V_38 )
{
struct V_23 * V_24 = F_19 ( V_38 , struct V_23 , V_25 ) ;
F_24 ( & V_24 -> V_44 ) ;
F_13 ( V_24 ) ;
F_25 ( & V_24 -> V_44 ) ;
F_28 ( V_38 -> V_6 ) ;
return 0 ;
}
static void F_31 ( struct V_49 * V_50 , struct V_5 * V_6 )
{
struct V_23 * V_38 = F_32 ( sizeof( * V_38 ) , V_51 ) ;
if ( ! V_38 )
return;
V_38 -> V_25 . V_6 = V_6 ;
V_38 -> V_25 . V_52 = V_6 -> V_53 ;
V_38 -> V_25 . V_35 = V_6 -> V_35 >> 9 ;
V_38 -> V_25 . V_50 = V_50 ;
if ( ! ( V_6 -> V_45 & V_54 ) )
V_38 -> V_25 . V_55 = 1 ;
if ( F_33 ( & V_38 -> V_25 ) )
F_34 ( V_38 ) ;
}
static void F_35 ( struct V_37 * V_38 )
{
F_36 ( V_38 ) ;
}
static int T_3 F_37 ( void )
{
return F_38 ( & V_56 ) ;
}
static void T_4 F_39 ( void )
{
F_40 ( & V_56 ) ;
}
