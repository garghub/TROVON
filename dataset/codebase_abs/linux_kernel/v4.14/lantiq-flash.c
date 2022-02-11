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
V_20 = F_8 ( & V_19 -> V_24 , sizeof( struct V_20 ) , V_25 ) ;
if ( ! V_20 )
return - V_26 ;
F_9 ( V_19 , V_20 ) ;
V_20 -> V_27 = F_10 ( V_19 , V_28 , 0 ) ;
if ( ! V_20 -> V_27 ) {
F_11 ( & V_19 -> V_24 , L_1 ) ;
return - V_29 ;
}
V_20 -> V_2 = F_8 ( & V_19 -> V_24 , sizeof( struct V_1 ) ,
V_25 ) ;
if ( ! V_20 -> V_2 )
return - V_26 ;
V_20 -> V_2 -> V_30 = V_20 -> V_27 -> V_31 ;
V_20 -> V_2 -> V_32 = F_12 ( V_20 -> V_27 ) ;
V_20 -> V_2 -> V_11 = F_13 ( & V_19 -> V_24 , V_20 -> V_27 ) ;
if ( F_14 ( V_20 -> V_2 -> V_11 ) )
return F_15 ( V_20 -> V_2 -> V_11 ) ;
V_20 -> V_2 -> V_33 = V_34 ;
V_20 -> V_2 -> V_35 = 2 ;
V_20 -> V_2 -> V_36 = F_1 ;
V_20 -> V_2 -> V_37 = F_4 ;
V_20 -> V_2 -> V_38 = F_5 ;
V_20 -> V_2 -> V_39 = F_6 ;
V_20 -> V_2 -> V_6 = V_7 ;
V_20 -> V_40 = F_16 ( L_2 , V_20 -> V_2 ) ;
V_20 -> V_2 -> V_6 = V_41 ;
if ( ! V_20 -> V_40 ) {
F_11 ( & V_19 -> V_24 , L_3 ) ;
return - V_42 ;
}
V_20 -> V_40 -> V_24 . V_43 = & V_19 -> V_24 ;
F_17 ( V_20 -> V_40 , V_19 -> V_24 . V_44 ) ;
V_22 = V_20 -> V_2 -> V_45 ;
V_22 -> V_46 ^= 1 ;
V_22 -> V_47 ^= 1 ;
V_23 = F_18 ( V_20 -> V_40 , NULL , 0 ) ;
if ( V_23 ) {
F_11 ( & V_19 -> V_24 , L_4 ) ;
goto V_48;
}
return 0 ;
V_48:
F_19 ( V_20 -> V_40 ) ;
return V_23 ;
}
static int
F_20 ( struct V_18 * V_19 )
{
struct V_20 * V_20 = F_21 ( V_19 ) ;
if ( V_20 && V_20 -> V_40 ) {
F_22 ( V_20 -> V_40 ) ;
F_19 ( V_20 -> V_40 ) ;
}
return 0 ;
}
