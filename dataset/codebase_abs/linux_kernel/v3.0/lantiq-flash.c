static T_1
F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
if ( V_2 -> V_6 == V_7 )
V_3 ^= 2 ;
F_2 ( & V_8 , V_4 ) ;
V_5 . V_9 [ 0 ] = * ( V_10 * ) ( V_2 -> V_11 + V_3 ) ;
F_3 ( & V_8 , V_4 ) ;
return V_5 ;
}
static void
F_4 ( struct V_1 * V_2 , T_1 V_12 , unsigned long V_3 )
{
unsigned long V_4 ;
if ( V_2 -> V_6 == V_7 )
V_3 ^= 2 ;
F_2 ( & V_8 , V_4 ) ;
* ( V_10 * ) ( V_2 -> V_11 + V_3 ) = V_12 . V_9 [ 0 ] ;
F_3 ( & V_8 , V_4 ) ;
}
static void
F_5 ( struct V_1 * V_2 , void * V_13 ,
unsigned long V_14 , T_2 V_15 )
{
unsigned char * V_16 = ( unsigned char * ) V_2 -> V_11 + V_14 ;
unsigned char * V_17 = ( unsigned char * ) V_13 ;
unsigned long V_4 ;
F_2 ( & V_8 , V_4 ) ;
while ( V_15 -- )
* V_17 ++ = * V_16 ++ ;
F_3 ( & V_8 , V_4 ) ;
}
static void
F_6 ( struct V_1 * V_2 , unsigned long V_13 ,
const void * V_14 , T_2 V_15 )
{
unsigned char * V_16 = ( unsigned char * ) V_14 ;
unsigned char * V_17 = ( unsigned char * ) V_2 -> V_11 + V_13 ;
unsigned long V_4 ;
F_2 ( & V_8 , V_4 ) ;
while ( V_15 -- )
* V_17 ++ = * V_16 ++ ;
F_3 ( & V_8 , V_4 ) ;
}
static int T_3
F_7 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_8 ( & V_19 -> V_22 ) ;
struct V_23 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_28 = 0 ;
struct V_29 * V_30 ;
int V_31 ;
V_23 = F_9 ( sizeof( struct V_23 ) , V_32 ) ;
F_10 ( V_19 , V_23 ) ;
V_23 -> V_27 = F_11 ( V_19 , V_33 , 0 ) ;
if ( ! V_23 -> V_27 ) {
F_12 ( & V_19 -> V_22 , L_1 ) ;
V_31 = - V_34 ;
goto V_35;
}
V_27 = F_13 ( & V_19 -> V_22 , V_23 -> V_27 -> V_36 ,
F_14 ( V_23 -> V_27 ) , F_15 ( & V_19 -> V_22 ) ) ;
if ( ! V_23 -> V_27 ) {
F_12 ( & V_19 -> V_22 , L_2 ) ;
V_31 = - V_37 ;
goto V_35;
}
V_23 -> V_2 = F_9 ( sizeof( struct V_1 ) , V_32 ) ;
V_23 -> V_2 -> V_38 = V_27 -> V_36 ;
V_23 -> V_2 -> V_39 = F_14 ( V_27 ) ;
V_23 -> V_2 -> V_11 = F_16 ( & V_19 -> V_22 ,
V_23 -> V_2 -> V_38 , V_23 -> V_2 -> V_39 ) ;
if ( ! V_23 -> V_2 -> V_11 ) {
F_12 ( & V_19 -> V_22 , L_3 ) ;
V_31 = - V_40 ;
goto V_41;
}
V_23 -> V_2 -> V_42 = V_43 ;
V_23 -> V_2 -> V_44 = 2 ;
V_23 -> V_2 -> V_45 = F_1 ;
V_23 -> V_2 -> V_46 = F_4 ;
V_23 -> V_2 -> V_47 = F_5 ;
V_23 -> V_2 -> V_48 = F_6 ;
V_23 -> V_2 -> V_6 = V_7 ;
V_23 -> V_49 = F_17 ( L_4 , V_23 -> V_2 ) ;
V_23 -> V_2 -> V_6 = V_50 ;
if ( ! V_23 -> V_49 ) {
F_12 ( & V_19 -> V_22 , L_5 ) ;
V_31 = - V_51 ;
goto V_52;
}
V_23 -> V_49 -> V_53 = V_54 ;
V_30 = V_23 -> V_2 -> V_55 ;
V_30 -> V_56 ^= 1 ;
V_30 -> V_57 ^= 1 ;
V_28 = F_18 ( V_23 -> V_49 ,
V_58 , & V_25 , 0 ) ;
if ( V_28 > 0 ) {
F_19 ( & V_19 -> V_22 ,
L_6 , V_28 ) ;
} else {
V_28 = V_21 -> V_28 ;
V_25 = V_21 -> V_25 ;
}
V_31 = F_20 ( V_23 -> V_49 , V_25 , V_28 ) ;
if ( V_31 ) {
F_12 ( & V_19 -> V_22 , L_7 ) ;
goto V_59;
}
return 0 ;
V_59:
F_21 ( V_23 -> V_49 ) ;
V_52:
F_22 ( V_23 -> V_2 -> V_11 ) ;
V_41:
F_23 ( V_23 -> V_2 ) ;
V_35:
F_23 ( V_23 ) ;
return V_31 ;
}
static int T_4
F_24 ( struct V_18 * V_19 )
{
struct V_23 * V_23 = F_25 ( V_19 ) ;
if ( V_23 ) {
if ( V_23 -> V_49 ) {
F_26 ( V_23 -> V_49 ) ;
F_21 ( V_23 -> V_49 ) ;
}
if ( V_23 -> V_2 -> V_11 )
F_22 ( V_23 -> V_2 -> V_11 ) ;
F_23 ( V_23 -> V_2 ) ;
F_23 ( V_23 ) ;
}
return 0 ;
}
static int T_3
F_27 ( void )
{
int V_60 = F_28 ( & V_61 , F_7 ) ;
if ( V_60 )
F_29 ( L_8 ) ;
return V_60 ;
}
static void T_5
F_30 ( void )
{
F_31 ( & V_61 ) ;
}
