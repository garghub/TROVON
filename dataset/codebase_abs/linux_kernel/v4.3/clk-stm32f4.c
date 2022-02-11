static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_3 ( V_6 + V_7 ) & F_4 ( V_5 -> V_8 ) )
return V_3 * 2 ;
return V_3 ;
}
static long F_5 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_11 = 1 ;
if ( F_3 ( V_6 + V_7 ) & F_4 ( V_5 -> V_8 ) )
V_11 = 2 ;
if ( F_6 ( V_2 ) & V_12 ) {
unsigned long V_13 = V_9 / V_11 ;
* V_10 = F_7 ( F_8 ( V_2 ) , V_13 ) ;
}
return * V_10 * V_11 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
return 0 ;
}
static struct V_14 * F_10 ( struct V_15 * V_16 , const char * V_17 ,
const char * V_18 ,
unsigned long V_19 , T_1 V_8 )
{
struct V_4 * V_5 ;
struct V_20 V_21 ;
struct V_14 * V_14 ;
V_5 = F_11 ( sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 )
return F_12 ( - V_23 ) ;
V_5 -> V_8 = V_8 ;
V_5 -> V_2 . V_21 = & V_21 ;
V_21 . V_17 = V_17 ;
V_21 . V_24 = & V_25 ;
V_21 . V_19 = V_19 ;
V_21 . V_26 = & V_18 ;
V_21 . V_27 = 1 ;
V_14 = F_13 ( V_16 , & V_5 -> V_2 ) ;
if ( F_14 ( V_14 ) )
F_15 ( V_5 ) ;
return V_14 ;
}
static void F_16 ( const char * V_28 , const char * V_29 )
{
unsigned long V_30 = F_3 ( V_6 + V_31 ) ;
unsigned long V_32 = V_30 & 0x3f ;
unsigned long V_33 = ( V_30 >> 6 ) & 0x1ff ;
unsigned long V_34 = F_4 ( ( ( V_30 >> 16 ) & 3 ) + 1 ) ;
const char * V_35 = V_30 & F_4 ( 22 ) ? V_28 : V_29 ;
unsigned long V_36 = ( V_30 >> 24 ) & 0xf ;
F_17 ( NULL , L_1 , V_35 , 0 , V_33 , V_32 ) ;
F_17 ( NULL , L_2 , L_1 , 0 , 1 , V_34 ) ;
F_17 ( NULL , L_3 , L_1 , 0 , 1 , V_36 ) ;
}
static int F_18 ( T_1 V_37 , T_1 V_38 )
{
T_2 V_39 [ F_19 ( V_40 ) ] ;
if ( V_37 == 1 ) {
if ( F_20 ( V_38 > V_41 ) )
return - V_42 ;
return V_38 ;
}
memcpy ( V_39 , V_40 , sizeof( V_39 ) ) ;
if ( F_20 ( V_38 >= V_43 * sizeof( V_39 ) ||
0 == ( V_39 [ F_21 ( V_38 ) ] &
F_22 ( V_38 ) ) ) )
return - V_42 ;
V_39 [ F_21 ( V_38 ) ] &=
F_23 ( V_38 % V_44 , 0 ) ;
return V_41 + F_24 ( V_39 [ 0 ] ) +
( F_21 ( V_38 ) >= 1 ? F_24 ( V_39 [ 1 ] ) : 0 ) +
( F_21 ( V_38 ) >= 2 ? F_24 ( V_39 [ 2 ] ) : 0 ) ;
}
static struct V_14 *
F_25 ( struct V_45 * V_46 , void * V_47 )
{
int V_48 = F_18 ( V_46 -> args [ 0 ] , V_46 -> args [ 1 ] ) ;
if ( V_48 < 0 )
return F_12 ( - V_42 ) ;
return V_49 [ V_48 ] ;
}
static void T_3 F_26 ( struct V_50 * V_51 )
{
const char * V_28 ;
int V_52 ;
V_6 = F_27 ( V_51 , 0 ) ;
if ( ! V_6 ) {
F_28 ( L_4 , V_51 -> V_17 ) ;
return;
}
V_28 = F_29 ( V_51 , 0 ) ;
F_30 ( NULL , L_5 , NULL , 0 ,
16000000 , 160000 ) ;
F_16 ( V_28 , L_5 ) ;
V_53 [ 1 ] = V_28 ;
F_31 (
NULL , L_6 , V_53 , F_19 ( V_53 ) , 0 ,
V_6 + V_7 , 0 , 3 , 0 , NULL , & V_54 ) ;
F_32 ( NULL , L_7 , L_6 ,
V_12 , V_6 + V_7 ,
4 , 4 , 0 , V_55 , & V_54 ) ;
F_32 ( NULL , L_8 , L_7 ,
V_12 , V_6 + V_7 ,
10 , 3 , 0 , V_56 , & V_54 ) ;
F_10 ( NULL , L_9 , L_8 ,
V_12 , 12 ) ;
F_32 ( NULL , L_10 , L_7 ,
V_12 , V_6 + V_7 ,
13 , 3 , 0 , V_56 , & V_54 ) ;
F_10 ( NULL , L_11 , L_10 ,
V_12 , 15 ) ;
V_49 [ V_57 ] = F_17 ( NULL , L_12 , L_7 ,
0 , 1 , 8 ) ;
V_49 [ V_41 ] = F_17 ( NULL , L_13 , L_7 ,
0 , 1 , 1 ) ;
for ( V_52 = 0 ; V_52 < F_19 ( V_58 ) ; V_52 ++ ) {
const struct V_59 * V_60 = & V_58 [ V_52 ] ;
unsigned int V_38 =
8 * ( V_60 -> V_61 - V_62 ) + V_60 -> V_8 ;
int V_63 = F_18 ( 0 , V_38 ) ;
if ( V_63 < 0 )
goto V_64;
V_49 [ V_63 ] = F_33 (
NULL , V_60 -> V_17 , V_60 -> V_18 , V_60 -> V_19 ,
V_6 + V_60 -> V_61 , V_60 -> V_8 , 0 , & V_54 ) ;
if ( F_14 ( V_49 [ V_52 ] ) ) {
F_28 ( L_14 ,
V_51 -> V_65 , V_60 -> V_17 ) ;
goto V_64;
}
}
F_34 ( V_51 , F_25 , NULL ) ;
return;
V_64:
F_35 ( V_6 ) ;
}
