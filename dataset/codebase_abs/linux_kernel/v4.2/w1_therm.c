static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( sizeof( struct V_4 ) ,
V_5 ) ;
if ( ! V_2 -> V_3 )
return - V_6 ;
F_3 ( F_4 ( V_2 -> V_3 ) , 1 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_7 = F_6 ( 1 , F_4 ( V_2 -> V_3 ) ) ;
while( V_7 ) {
F_7 ( 1000 ) ;
V_7 = F_8 ( F_4 ( V_2 -> V_3 ) ) ;
}
F_9 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static inline int F_10 ( T_1 V_8 [ 9 ] )
{
T_2 V_9 = F_11 ( ( V_10 * ) V_8 ) ;
return V_9 * 1000 / 16 ;
}
static inline int F_12 ( T_1 V_8 [ 9 ] )
{
int V_9 , V_11 ;
if ( ! V_8 [ 7 ] )
return 0 ;
if ( V_8 [ 1 ] == 0 )
V_9 = ( ( V_12 ) V_8 [ 0 ] >> 1 ) * 1000 ;
else
V_9 = 1000 * ( - 1 * ( V_12 ) ( 0x100 - V_8 [ 0 ] ) >> 1 ) ;
V_9 -= 250 ;
V_11 = 1000 * ( ( V_12 ) V_8 [ 7 ] - ( V_12 ) V_8 [ 6 ] ) ;
V_11 /= ( V_12 ) V_8 [ 7 ] ;
V_9 += V_11 ;
return V_9 ;
}
static inline int F_13 ( T_1 V_8 [ 9 ] , T_1 V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < F_14 ( V_15 ) ; ++ V_14 )
if ( V_15 [ V_14 ] . V_16 -> V_13 == V_13 )
return V_15 [ V_14 ] . F_15 ( V_8 ) ;
return 0 ;
}
static T_3 F_16 ( struct V_17 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_1 * V_2 = F_17 ( V_17 ) ;
struct V_21 * V_22 = V_2 -> V_23 ;
T_1 V_8 [ 9 ] , V_24 , V_25 , V_26 ;
int V_14 , V_27 , V_28 = 10 ;
T_3 V_29 = V_30 ;
T_1 * V_3 = V_2 -> V_3 ;
V_27 = F_18 ( & V_22 -> V_31 ) ;
if ( V_27 != 0 )
goto V_32;
if( ! V_2 -> V_3 )
{
V_27 = - V_33 ;
goto V_34;
}
F_19 ( F_4 ( V_3 ) ) ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
while ( V_28 -- ) {
V_25 = 0 ;
V_24 = 0 ;
if ( ! F_20 ( V_2 ) ) {
int V_35 = 0 ;
unsigned int V_36 = 750 ;
unsigned long V_37 ;
F_21 ( V_22 , V_38 ) ;
V_26 = F_22 ( V_22 ) ;
if ( F_20 ( V_2 ) )
continue;
if ( V_39 == 2 ||
( ! V_26 && V_39 ) )
F_23 ( V_22 , V_36 ) ;
F_21 ( V_22 , V_40 ) ;
if ( V_26 ) {
F_24 ( & V_22 -> V_31 ) ;
V_37 = F_25 ( V_36 ) ;
if ( V_37 != 0 ) {
V_27 = - V_41 ;
goto V_32;
}
V_27 = F_18 ( & V_22 -> V_31 ) ;
if ( V_27 != 0 )
goto V_32;
} else if ( ! V_39 ) {
V_37 = F_25 ( V_36 ) ;
if ( V_37 != 0 ) {
V_27 = - V_41 ;
goto V_34;
}
}
if ( ! F_20 ( V_2 ) ) {
F_21 ( V_22 , V_42 ) ;
if ( ( V_35 = F_26 ( V_22 , V_8 , 9 ) ) != 9 ) {
F_27 ( V_17 , L_1
L_2 ,
V_35 ) ;
}
V_24 = F_28 ( V_8 , 8 ) ;
if ( V_8 [ 8 ] == V_24 )
V_25 = 1 ;
}
}
if ( V_25 )
break;
}
for ( V_14 = 0 ; V_14 < 9 ; ++ V_14 )
V_29 -= snprintf ( V_20 + V_30 - V_29 , V_29 , L_3 , V_8 [ V_14 ] ) ;
V_29 -= snprintf ( V_20 + V_30 - V_29 , V_29 , L_4 ,
V_24 , ( V_25 ) ? L_5 : L_6 ) ;
if ( V_25 )
memcpy ( V_3 , V_8 , sizeof( V_8 ) ) ;
else
F_27 ( V_17 , L_7 ) ;
for ( V_14 = 0 ; V_14 < 9 ; ++ V_14 )
V_29 -= snprintf ( V_20 + V_30 - V_29 , V_29 , L_3 ,
( ( T_1 * ) V_3 ) [ V_14 ] ) ;
V_29 -= snprintf ( V_20 + V_30 - V_29 , V_29 , L_8 ,
F_13 ( V_8 , V_2 -> V_43 -> V_13 ) ) ;
V_27 = V_30 - V_29 ;
V_34:
F_24 ( & V_22 -> V_31 ) ;
V_32:
F_29 ( F_4 ( V_3 ) ) ;
return V_27 ;
}
static T_3 F_30 ( struct V_17 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_1 * V_2 = F_17 ( V_17 ) ;
T_3 V_29 = V_30 ;
int V_44 ;
int V_14 ;
T_1 V_45 ;
T_4 V_46 ;
struct V_47 * V_48 ;
int V_49 = 0 ;
F_31 ( & V_2 -> V_23 -> V_31 ) ;
if ( F_32 ( V_2 -> V_23 ) )
goto error;
F_21 ( V_2 -> V_23 , V_50 ) ;
F_21 ( V_2 -> V_23 , V_51 ) ;
F_21 ( V_2 -> V_23 , V_52 ) ;
F_21 ( V_2 -> V_23 , V_53 ) ;
F_7 ( V_2 -> V_23 -> V_54 ) ;
V_45 = F_22 ( V_2 -> V_23 ) ;
if ( V_45 != V_55 )
goto error;
for ( V_14 = 0 ; V_14 <= 64 ; V_14 ++ ) {
if ( F_32 ( V_2 -> V_23 ) )
goto error;
F_21 ( V_2 -> V_23 , V_56 ) ;
V_44 = F_26 ( V_2 -> V_23 , ( T_1 * ) & V_46 , 8 ) ;
V_48 = (struct V_47 * ) & V_46 ;
if ( V_48 -> V_43 == V_57 )
break;
if ( V_2 -> V_48 . V_58 == V_48 -> V_58 )
V_49 = V_14 ;
F_21 ( V_2 -> V_23 , V_51 ) ;
F_21 ( V_2 -> V_23 , V_59 ) ;
F_21 ( V_2 -> V_23 , V_60 ) ;
F_26 ( V_2 -> V_23 , & V_45 , sizeof( V_45 ) ) ;
V_45 = F_22 ( V_2 -> V_23 ) ;
if ( V_45 != V_55 )
goto error;
}
if ( F_32 ( V_2 -> V_23 ) )
goto error;
F_21 ( V_2 -> V_23 , V_50 ) ;
F_21 ( V_2 -> V_23 , V_51 ) ;
F_21 ( V_2 -> V_23 , V_61 ) ;
F_21 ( V_2 -> V_23 , V_62 ) ;
V_45 = F_22 ( V_2 -> V_23 ) ;
if ( V_45 != V_55 )
goto error;
F_24 ( & V_2 -> V_23 -> V_31 ) ;
V_29 -= snprintf ( V_20 + V_30 - V_29 , V_29 , L_9 , V_49 ) ;
return V_30 - V_29 ;
error:
F_24 ( & V_2 -> V_23 -> V_31 ) ;
return - V_63 ;
}
static int T_5 F_33 ( void )
{
int V_64 , V_14 ;
for ( V_14 = 0 ; V_14 < F_14 ( V_15 ) ; ++ V_14 ) {
V_64 = F_34 ( V_15 [ V_14 ] . V_16 ) ;
if ( V_64 )
V_15 [ V_14 ] . V_65 = 1 ;
}
return 0 ;
}
static void T_6 F_35 ( void )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < F_14 ( V_15 ) ; ++ V_14 )
if ( ! V_15 [ V_14 ] . V_65 )
F_36 ( V_15 [ V_14 ] . V_16 ) ;
}
