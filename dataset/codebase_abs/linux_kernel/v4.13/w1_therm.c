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
while ( V_7 ) {
F_7 ( 1000 ) ;
V_7 = F_8 ( F_4 ( V_2 -> V_3 ) ) ;
}
F_9 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static inline int F_10 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_11 ( V_8 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
T_1 V_12 [ 9 ] , V_13 ;
int V_14 , V_15 = 10 ;
T_1 * V_3 = V_2 -> V_3 ;
V_14 = F_12 ( & V_10 -> V_16 ) ;
if ( V_14 != 0 )
goto V_17;
if ( ! V_2 -> V_3 ) {
V_14 = - V_18 ;
goto V_19;
}
F_13 ( F_4 ( V_3 ) ) ;
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
while ( V_15 -- ) {
if ( ! F_14 ( V_2 ) ) {
unsigned int V_20 = 10 ;
unsigned long V_21 ;
F_15 ( V_10 , V_22 ) ;
V_13 = F_16 ( V_10 ) ;
if ( F_14 ( V_2 ) )
continue;
if ( V_23 == 2 ||
( ! V_13 && V_23 ) )
F_17 ( V_10 , V_20 ) ;
F_15 ( V_10 , V_24 ) ;
if ( V_13 ) {
F_18 ( & V_10 -> V_16 ) ;
V_21 = F_19 ( V_20 ) ;
if ( V_21 != 0 ) {
V_14 = - V_25 ;
goto V_17;
}
V_14 = F_12 ( & V_10 -> V_16 ) ;
if ( V_14 != 0 )
goto V_17;
} else if ( ! V_23 ) {
V_21 = F_19 ( V_20 ) ;
if ( V_21 != 0 ) {
V_14 = - V_25 ;
goto V_19;
}
}
break;
}
}
V_19:
F_18 ( & V_10 -> V_16 ) ;
V_17:
F_20 ( F_4 ( V_3 ) ) ;
return V_14 ;
}
static inline int F_21 ( struct V_8 * V_8 , int V_26 )
{
return 0 ;
}
static inline int F_22 ( struct V_8 * V_8 , int V_26 )
{
struct V_1 * V_2 = F_11 ( V_8 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
T_1 V_12 [ 9 ] , V_27 ;
int V_14 , V_15 = 10 ;
T_1 * V_3 = V_2 -> V_3 ;
T_2 V_28 ;
T_2 V_29 = 0x60 ;
if ( V_26 > 12 || V_26 < 9 ) {
F_23 ( L_1 ) ;
return - 1 ;
}
V_14 = F_12 ( & V_10 -> V_16 ) ;
if ( V_14 != 0 )
goto V_17;
if ( ! V_2 -> V_3 ) {
V_14 = - V_18 ;
goto V_19;
}
F_13 ( F_4 ( V_3 ) ) ;
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
switch ( V_26 ) {
case 9 :
V_28 = 0x00 ;
break;
case 10 :
V_28 = 0x20 ;
break;
case 11 :
V_28 = 0x40 ;
break;
case 12 :
default:
V_28 = 0x60 ;
break;
}
while ( V_15 -- ) {
V_27 = 0 ;
if ( ! F_14 ( V_2 ) ) {
int V_30 = 0 ;
F_15 ( V_10 , V_31 ) ;
V_30 = F_24 ( V_10 , V_12 , 9 ) ;
if ( V_30 != 9 )
F_25 ( V_8 , L_2 , V_30 ) ;
V_27 = F_26 ( V_12 , 8 ) ;
if ( V_12 [ 8 ] == V_27 ) {
V_12 [ 4 ] = ( V_12 [ 4 ] & ~ V_29 ) | ( V_28 & V_29 ) ;
if ( ! F_14 ( V_2 ) ) {
F_15 ( V_10 , V_32 ) ;
F_15 ( V_10 , V_12 [ 2 ] ) ;
F_15 ( V_10 , V_12 [ 3 ] ) ;
F_15 ( V_10 , V_12 [ 4 ] ) ;
break;
}
}
}
}
V_19:
F_18 ( & V_10 -> V_16 ) ;
V_17:
F_20 ( F_4 ( V_3 ) ) ;
return V_14 ;
}
static inline int F_27 ( T_1 V_12 [ 9 ] )
{
T_3 V_33 = F_28 ( ( V_34 * ) V_12 ) ;
return V_33 * 1000 / 16 ;
}
static inline int F_29 ( T_1 V_12 [ 9 ] )
{
int V_33 , V_35 ;
if ( ! V_12 [ 7 ] )
return 0 ;
if ( V_12 [ 1 ] == 0 )
V_33 = ( ( V_36 ) V_12 [ 0 ] >> 1 ) * 1000 ;
else
V_33 = 1000 * ( - 1 * ( V_36 ) ( 0x100 - V_12 [ 0 ] ) >> 1 ) ;
V_33 -= 250 ;
V_35 = 1000 * ( ( V_36 ) V_12 [ 7 ] - ( V_36 ) V_12 [ 6 ] ) ;
V_35 /= ( V_36 ) V_12 [ 7 ] ;
V_33 += V_35 ;
return V_33 ;
}
static inline int F_30 ( T_1 V_12 [ 9 ] , T_1 V_37 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < F_31 ( V_39 ) ; ++ V_38 )
if ( V_39 [ V_38 ] . V_40 -> V_37 == V_37 )
return V_39 [ V_38 ] . F_32 ( V_12 ) ;
return 0 ;
}
static T_4 F_33 ( struct V_8 * V_8 ,
struct V_41 * V_42 , const char * V_43 ,
T_5 V_44 )
{
int V_26 , V_14 ;
struct V_1 * V_2 = F_11 ( V_8 ) ;
int V_38 ;
V_14 = F_34 ( V_43 , 0 , & V_26 ) ;
if ( V_14 )
return V_14 ;
for ( V_38 = 0 ; V_38 < F_31 ( V_39 ) ; ++ V_38 ) {
if ( V_39 [ V_38 ] . V_40 -> V_37 == V_2 -> V_45 -> V_37 ) {
if ( V_26 == 0 )
V_14 = V_39 [ V_38 ] . F_35 ( V_8 ) ;
else
V_14 = V_39 [ V_38 ] . F_36 ( V_8 , V_26 ) ;
break;
}
}
return V_14 ? : V_44 ;
}
static T_4 F_37 ( struct V_8 * V_8 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_1 * V_2 = F_11 ( V_8 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
T_1 V_12 [ 9 ] , V_27 , V_46 , V_13 ;
int V_38 , V_14 , V_15 = 10 ;
T_4 V_47 = V_48 ;
T_1 * V_3 = V_2 -> V_3 ;
V_14 = F_12 ( & V_10 -> V_16 ) ;
if ( V_14 != 0 )
goto V_17;
if ( ! V_2 -> V_3 ) {
V_14 = - V_18 ;
goto V_19;
}
F_13 ( F_4 ( V_3 ) ) ;
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
while ( V_15 -- ) {
V_46 = 0 ;
V_27 = 0 ;
if ( ! F_14 ( V_2 ) ) {
int V_30 = 0 ;
unsigned int V_20 = 750 ;
unsigned long V_21 ;
F_15 ( V_10 , V_22 ) ;
V_13 = F_16 ( V_10 ) ;
if ( F_14 ( V_2 ) )
continue;
if ( V_23 == 2 ||
( ! V_13 && V_23 ) )
F_17 ( V_10 , V_20 ) ;
F_15 ( V_10 , V_49 ) ;
if ( V_13 ) {
F_18 ( & V_10 -> V_16 ) ;
V_21 = F_19 ( V_20 ) ;
if ( V_21 != 0 ) {
V_14 = - V_25 ;
goto V_17;
}
V_14 = F_12 ( & V_10 -> V_16 ) ;
if ( V_14 != 0 )
goto V_17;
} else if ( ! V_23 ) {
V_21 = F_19 ( V_20 ) ;
if ( V_21 != 0 ) {
V_14 = - V_25 ;
goto V_19;
}
}
if ( ! F_14 ( V_2 ) ) {
F_15 ( V_10 , V_31 ) ;
V_30 = F_24 ( V_10 , V_12 , 9 ) ;
if ( V_30 != 9 ) {
F_25 ( V_8 , L_3
L_4 ,
V_30 ) ;
}
V_27 = F_26 ( V_12 , 8 ) ;
if ( V_12 [ 8 ] == V_27 )
V_46 = 1 ;
}
}
if ( V_46 )
break;
}
for ( V_38 = 0 ; V_38 < 9 ; ++ V_38 )
V_47 -= snprintf ( V_43 + V_48 - V_47 , V_47 , L_5 , V_12 [ V_38 ] ) ;
V_47 -= snprintf ( V_43 + V_48 - V_47 , V_47 , L_6 ,
V_27 , ( V_46 ) ? L_7 : L_8 ) ;
if ( V_46 )
memcpy ( V_3 , V_12 , sizeof( V_12 ) ) ;
else
F_25 ( V_8 , L_9 ) ;
for ( V_38 = 0 ; V_38 < 9 ; ++ V_38 )
V_47 -= snprintf ( V_43 + V_48 - V_47 , V_47 , L_5 ,
( ( T_1 * ) V_3 ) [ V_38 ] ) ;
V_47 -= snprintf ( V_43 + V_48 - V_47 , V_47 , L_10 ,
F_30 ( V_12 , V_2 -> V_45 -> V_37 ) ) ;
V_14 = V_48 - V_47 ;
V_19:
F_18 ( & V_10 -> V_16 ) ;
V_17:
F_20 ( F_4 ( V_3 ) ) ;
return V_14 ;
}
static T_4 F_38 ( struct V_8 * V_8 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_1 * V_2 = F_11 ( V_8 ) ;
T_4 V_47 = V_48 ;
int V_50 ;
int V_38 ;
T_1 V_51 ;
T_6 V_52 ;
struct V_53 * V_54 ;
int V_55 = 0 ;
F_39 ( & V_2 -> V_11 -> V_16 ) ;
if ( F_40 ( V_2 -> V_11 ) )
goto error;
F_15 ( V_2 -> V_11 , V_56 ) ;
F_15 ( V_2 -> V_11 , V_57 ) ;
F_15 ( V_2 -> V_11 , V_58 ) ;
F_15 ( V_2 -> V_11 , V_59 ) ;
F_7 ( V_2 -> V_11 -> V_60 ) ;
V_51 = F_16 ( V_2 -> V_11 ) ;
if ( V_51 != V_61 )
goto error;
for ( V_38 = 0 ; V_38 <= 64 ; V_38 ++ ) {
if ( F_40 ( V_2 -> V_11 ) )
goto error;
F_15 ( V_2 -> V_11 , V_62 ) ;
V_50 = F_24 ( V_2 -> V_11 , ( T_1 * ) & V_52 , 8 ) ;
V_54 = (struct V_53 * ) & V_52 ;
if ( V_54 -> V_45 == V_63 )
break;
if ( V_2 -> V_54 . V_64 == V_54 -> V_64 )
V_55 = V_38 ;
F_15 ( V_2 -> V_11 , V_57 ) ;
F_15 ( V_2 -> V_11 , V_65 ) ;
F_15 ( V_2 -> V_11 , V_66 ) ;
F_24 ( V_2 -> V_11 , & V_51 , sizeof( V_51 ) ) ;
V_51 = F_16 ( V_2 -> V_11 ) ;
if ( V_51 != V_61 )
goto error;
}
if ( F_40 ( V_2 -> V_11 ) )
goto error;
F_15 ( V_2 -> V_11 , V_56 ) ;
F_15 ( V_2 -> V_11 , V_57 ) ;
F_15 ( V_2 -> V_11 , V_67 ) ;
F_15 ( V_2 -> V_11 , V_68 ) ;
V_51 = F_16 ( V_2 -> V_11 ) ;
if ( V_51 != V_61 )
goto error;
F_18 ( & V_2 -> V_11 -> V_16 ) ;
V_47 -= snprintf ( V_43 + V_48 - V_47 , V_47 , L_11 , V_55 ) ;
return V_48 - V_47 ;
error:
F_18 ( & V_2 -> V_11 -> V_16 ) ;
return - V_69 ;
}
static int T_7 F_41 ( void )
{
int V_70 , V_38 ;
for ( V_38 = 0 ; V_38 < F_31 ( V_39 ) ; ++ V_38 ) {
V_70 = F_42 ( V_39 [ V_38 ] . V_40 ) ;
if ( V_70 )
V_39 [ V_38 ] . V_71 = 1 ;
}
return 0 ;
}
static void T_8 F_43 ( void )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < F_31 ( V_39 ) ; ++ V_38 )
if ( ! V_39 [ V_38 ] . V_71 )
F_44 ( V_39 [ V_38 ] . V_40 ) ;
}
