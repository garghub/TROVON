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
static int
F_7 ( struct V_18 * V_19 )
{
struct V_20 * V_20 ;
struct V_21 * V_22 ;
int V_23 ;
if ( F_8 ( L_1 ) &&
( F_9 () != V_24 ) ) {
F_10 ( & V_19 -> V_25 , L_2 ) ;
return - V_26 ;
}
V_20 = F_11 ( & V_19 -> V_25 , sizeof( struct V_20 ) , V_27 ) ;
if ( ! V_20 )
return - V_28 ;
F_12 ( V_19 , V_20 ) ;
V_20 -> V_29 = F_13 ( V_19 , V_30 , 0 ) ;
if ( ! V_20 -> V_29 ) {
F_10 ( & V_19 -> V_25 , L_3 ) ;
return - V_31 ;
}
V_20 -> V_2 = F_11 ( & V_19 -> V_25 , sizeof( struct V_1 ) ,
V_27 ) ;
if ( ! V_20 -> V_2 )
return - V_28 ;
V_20 -> V_2 -> V_32 = V_20 -> V_29 -> V_33 ;
V_20 -> V_2 -> V_34 = F_14 ( V_20 -> V_29 ) ;
V_20 -> V_2 -> V_11 = F_15 ( & V_19 -> V_25 , V_20 -> V_29 ) ;
if ( F_16 ( V_20 -> V_2 -> V_11 ) )
return F_17 ( V_20 -> V_2 -> V_11 ) ;
V_20 -> V_2 -> V_35 = V_36 ;
V_20 -> V_2 -> V_37 = 2 ;
V_20 -> V_2 -> V_38 = F_1 ;
V_20 -> V_2 -> V_39 = F_4 ;
V_20 -> V_2 -> V_40 = F_5 ;
V_20 -> V_2 -> V_41 = F_6 ;
V_20 -> V_2 -> V_6 = V_7 ;
V_20 -> V_42 = F_18 ( L_4 , V_20 -> V_2 ) ;
V_20 -> V_2 -> V_6 = V_43 ;
if ( ! V_20 -> V_42 ) {
F_10 ( & V_19 -> V_25 , L_5 ) ;
return - V_44 ;
}
V_20 -> V_42 -> V_25 . V_45 = & V_19 -> V_25 ;
F_19 ( V_20 -> V_42 , V_19 -> V_25 . V_46 ) ;
V_22 = V_20 -> V_2 -> V_47 ;
V_22 -> V_48 ^= 1 ;
V_22 -> V_49 ^= 1 ;
V_23 = F_20 ( V_20 -> V_42 , NULL , 0 ) ;
if ( V_23 ) {
F_10 ( & V_19 -> V_25 , L_6 ) ;
goto V_50;
}
return 0 ;
V_50:
F_21 ( V_20 -> V_42 ) ;
return V_23 ;
}
static int
F_22 ( struct V_18 * V_19 )
{
struct V_20 * V_20 = F_23 ( V_19 ) ;
if ( V_20 && V_20 -> V_42 ) {
F_24 ( V_20 -> V_42 ) ;
F_21 ( V_20 -> V_42 ) ;
}
return 0 ;
}
