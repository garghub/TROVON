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
static T_1 F_10 ( const void * V_8 , enum V_9 type ,
T_2 V_10 , int V_11 )
{
return V_10 == V_12 ? 0444 : 0 ;
}
static int F_11 ( struct V_13 * V_14 , enum V_9 type ,
T_2 V_10 , int V_11 , long * V_15 )
{
switch ( type ) {
case V_16 :
return F_12 ( V_14 , V_10 , V_11 , V_15 ) ;
default:
return - V_17 ;
}
}
static inline int F_13 ( struct V_13 * V_13 )
{
struct V_1 * V_2 = F_14 ( V_13 ) ;
struct V_18 * V_14 = V_2 -> V_19 ;
T_3 V_20 [ 9 ] , V_21 ;
int V_22 , V_23 = 10 ;
T_3 * V_3 = V_2 -> V_3 ;
V_22 = F_15 ( & V_14 -> V_24 ) ;
if ( V_22 != 0 )
goto V_25;
if ( ! V_2 -> V_3 ) {
V_22 = - V_26 ;
goto V_27;
}
F_16 ( F_4 ( V_3 ) ) ;
memset ( V_20 , 0 , sizeof( V_20 ) ) ;
while ( V_23 -- ) {
if ( ! F_17 ( V_2 ) ) {
unsigned int V_28 = 10 ;
unsigned long V_29 ;
F_18 ( V_14 , V_30 ) ;
V_21 = F_19 ( V_14 ) ;
if ( F_17 ( V_2 ) )
continue;
if ( V_31 == 2 ||
( ! V_21 && V_31 ) )
F_20 ( V_14 , V_28 ) ;
F_18 ( V_14 , V_32 ) ;
if ( V_21 ) {
F_21 ( & V_14 -> V_24 ) ;
V_29 = F_22 ( V_28 ) ;
if ( V_29 != 0 ) {
V_22 = - V_33 ;
goto V_25;
}
V_22 = F_15 ( & V_14 -> V_24 ) ;
if ( V_22 != 0 )
goto V_25;
} else if ( ! V_31 ) {
V_29 = F_22 ( V_28 ) ;
if ( V_29 != 0 ) {
V_22 = - V_33 ;
goto V_27;
}
}
break;
}
}
V_27:
F_21 ( & V_14 -> V_24 ) ;
V_25:
F_23 ( F_4 ( V_3 ) ) ;
return V_22 ;
}
static inline int F_24 ( struct V_13 * V_13 , int V_15 )
{
return 0 ;
}
static inline int F_25 ( struct V_13 * V_13 , int V_15 )
{
struct V_1 * V_2 = F_14 ( V_13 ) ;
struct V_18 * V_14 = V_2 -> V_19 ;
T_3 V_20 [ 9 ] , V_34 ;
int V_22 , V_23 = 10 ;
T_3 * V_3 = V_2 -> V_3 ;
T_4 V_35 ;
T_4 V_36 = 0x60 ;
if ( V_15 > 12 || V_15 < 9 ) {
F_26 ( L_1 ) ;
return - 1 ;
}
V_22 = F_15 ( & V_14 -> V_24 ) ;
if ( V_22 != 0 )
goto V_25;
if ( ! V_2 -> V_3 ) {
V_22 = - V_26 ;
goto V_27;
}
F_16 ( F_4 ( V_3 ) ) ;
memset ( V_20 , 0 , sizeof( V_20 ) ) ;
switch ( V_15 ) {
case 9 :
V_35 = 0x00 ;
break;
case 10 :
V_35 = 0x20 ;
break;
case 11 :
V_35 = 0x40 ;
break;
case 12 :
default:
V_35 = 0x60 ;
break;
}
while ( V_23 -- ) {
V_34 = 0 ;
if ( ! F_17 ( V_2 ) ) {
int V_37 = 0 ;
F_18 ( V_14 , V_38 ) ;
V_37 = F_27 ( V_14 , V_20 , 9 ) ;
if ( V_37 != 9 )
F_28 ( V_13 , L_2 , V_37 ) ;
V_34 = F_29 ( V_20 , 8 ) ;
if ( V_20 [ 8 ] == V_34 ) {
V_20 [ 4 ] = ( V_20 [ 4 ] & ~ V_36 ) | ( V_35 & V_36 ) ;
if ( ! F_17 ( V_2 ) ) {
F_18 ( V_14 , V_39 ) ;
F_18 ( V_14 , V_20 [ 2 ] ) ;
F_18 ( V_14 , V_20 [ 3 ] ) ;
F_18 ( V_14 , V_20 [ 4 ] ) ;
break;
}
}
}
}
V_27:
F_21 ( & V_14 -> V_24 ) ;
V_25:
F_23 ( F_4 ( V_3 ) ) ;
return V_22 ;
}
static inline int F_30 ( T_3 V_20 [ 9 ] )
{
T_5 V_40 = F_31 ( ( V_41 * ) V_20 ) ;
return V_40 * 1000 / 16 ;
}
static inline int F_32 ( T_3 V_20 [ 9 ] )
{
int V_40 , V_42 ;
if ( ! V_20 [ 7 ] )
return 0 ;
if ( V_20 [ 1 ] == 0 )
V_40 = ( ( V_43 ) V_20 [ 0 ] >> 1 ) * 1000 ;
else
V_40 = 1000 * ( - 1 * ( V_43 ) ( 0x100 - V_20 [ 0 ] ) >> 1 ) ;
V_40 -= 250 ;
V_42 = 1000 * ( ( V_43 ) V_20 [ 7 ] - ( V_43 ) V_20 [ 6 ] ) ;
V_42 /= ( V_43 ) V_20 [ 7 ] ;
V_40 += V_42 ;
return V_40 ;
}
static inline int F_33 ( T_3 V_20 [ 9 ] , T_3 V_44 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < F_34 ( V_46 ) ; ++ V_45 )
if ( V_46 [ V_45 ] . V_47 -> V_44 == V_44 )
return V_46 [ V_45 ] . F_35 ( V_20 ) ;
return 0 ;
}
static T_6 F_36 ( struct V_13 * V_13 ,
struct V_48 * V_10 , const char * V_49 ,
T_7 V_50 )
{
int V_15 , V_22 ;
struct V_1 * V_2 = F_14 ( V_13 ) ;
int V_45 ;
V_22 = F_37 ( V_49 , 0 , & V_15 ) ;
if ( V_22 )
return V_22 ;
for ( V_45 = 0 ; V_45 < F_34 ( V_46 ) ; ++ V_45 ) {
if ( V_46 [ V_45 ] . V_47 -> V_44 == V_2 -> V_51 -> V_44 ) {
if ( V_15 == 0 )
V_22 = V_46 [ V_45 ] . F_38 ( V_13 ) ;
else
V_22 = V_46 [ V_45 ] . F_39 ( V_13 , V_15 ) ;
break;
}
}
return V_22 ? : V_50 ;
}
static T_6 F_40 ( struct V_13 * V_13 ,
struct V_1 * V_2 , struct V_52 * V_53 )
{
struct V_18 * V_14 = V_2 -> V_19 ;
T_3 V_21 ;
int V_22 , V_23 = 10 ;
T_3 * V_3 = V_2 -> V_3 ;
V_22 = F_15 ( & V_14 -> V_24 ) ;
if ( V_22 != 0 )
goto error;
if ( ! V_3 ) {
V_22 = - V_26 ;
goto V_54;
}
F_16 ( F_4 ( V_3 ) ) ;
memset ( V_53 -> V_20 , 0 , sizeof( V_53 -> V_20 ) ) ;
while ( V_23 -- ) {
V_53 -> V_55 = 0 ;
V_53 -> V_34 = 0 ;
if ( ! F_17 ( V_2 ) ) {
int V_37 = 0 ;
unsigned int V_28 = 750 ;
unsigned long V_29 ;
F_18 ( V_14 , V_30 ) ;
V_21 = F_19 ( V_14 ) ;
if ( F_17 ( V_2 ) )
continue;
if ( V_31 == 2 ||
( ! V_21 && V_31 ) )
F_20 ( V_14 , V_28 ) ;
F_18 ( V_14 , V_56 ) ;
if ( V_21 ) {
F_21 ( & V_14 -> V_24 ) ;
V_29 = F_22 ( V_28 ) ;
if ( V_29 != 0 ) {
V_22 = - V_33 ;
goto V_57;
}
V_22 = F_15 ( & V_14 -> V_24 ) ;
if ( V_22 != 0 )
goto V_57;
} else if ( ! V_31 ) {
V_29 = F_22 ( V_28 ) ;
if ( V_29 != 0 ) {
V_22 = - V_33 ;
goto V_57;
}
}
if ( ! F_17 ( V_2 ) ) {
F_18 ( V_14 , V_38 ) ;
V_37 = F_27 ( V_14 , V_53 -> V_20 , 9 ) ;
if ( V_37 != 9 ) {
F_28 ( V_13 , L_3
L_4 ,
V_37 ) ;
}
V_53 -> V_34 = F_29 ( V_53 -> V_20 , 8 ) ;
if ( V_53 -> V_20 [ 8 ] == V_53 -> V_34 )
V_53 -> V_55 = 1 ;
}
}
if ( V_53 -> V_55 )
break;
}
V_57:
F_23 ( F_4 ( V_3 ) ) ;
V_54:
F_21 ( & V_14 -> V_24 ) ;
error:
return V_22 ;
}
static T_6 F_41 ( struct V_13 * V_13 ,
struct V_48 * V_10 , char * V_49 )
{
struct V_1 * V_2 = F_14 ( V_13 ) ;
struct V_52 V_53 ;
T_3 * V_3 = V_2 -> V_3 ;
int V_22 , V_45 ;
T_6 V_58 = V_59 ;
T_3 V_44 = V_2 -> V_51 -> V_44 ;
V_22 = F_40 ( V_13 , V_2 , & V_53 ) ;
if ( V_22 )
return V_22 ;
for ( V_45 = 0 ; V_45 < 9 ; ++ V_45 )
V_58 -= snprintf ( V_49 + V_59 - V_58 , V_58 , L_5 , V_53 . V_20 [ V_45 ] ) ;
V_58 -= snprintf ( V_49 + V_59 - V_58 , V_58 , L_6 ,
V_53 . V_34 , ( V_53 . V_55 ) ? L_7 : L_8 ) ;
if ( V_53 . V_55 )
memcpy ( V_3 , V_53 . V_20 , sizeof( V_53 . V_20 ) ) ;
else
F_28 ( V_13 , L_9 ) ;
for ( V_45 = 0 ; V_45 < 9 ; ++ V_45 )
V_58 -= snprintf ( V_49 + V_59 - V_58 , V_58 , L_5 ,
( ( T_3 * ) V_3 ) [ V_45 ] ) ;
V_58 -= snprintf ( V_49 + V_59 - V_58 , V_58 , L_10 ,
F_33 ( V_53 . V_20 , V_44 ) ) ;
V_22 = V_59 - V_58 ;
return V_22 ;
}
static int F_12 ( struct V_13 * V_13 , T_2 V_10 , int V_11 ,
long * V_15 )
{
struct V_1 * V_2 = F_42 ( V_13 ) ;
struct V_52 V_53 ;
T_3 V_44 = V_2 -> V_51 -> V_44 ;
int V_22 ;
switch ( V_10 ) {
case V_12 :
V_22 = F_40 ( V_13 , V_2 , & V_53 ) ;
if ( V_22 )
return V_22 ;
if ( ! V_53 . V_55 ) {
V_22 = - V_60 ;
return V_22 ;
}
* V_15 = F_33 ( V_53 . V_20 , V_44 ) ;
V_22 = 0 ;
break;
default:
V_22 = - V_17 ;
break;
}
return V_22 ;
}
static T_6 F_43 ( struct V_13 * V_13 ,
struct V_48 * V_10 , char * V_49 )
{
struct V_1 * V_2 = F_14 ( V_13 ) ;
T_6 V_58 = V_59 ;
int V_61 ;
int V_45 ;
T_3 V_62 ;
T_8 V_63 ;
struct V_64 * V_65 ;
int V_66 = 0 ;
F_44 ( & V_2 -> V_19 -> V_24 ) ;
if ( F_45 ( V_2 -> V_19 ) )
goto error;
F_18 ( V_2 -> V_19 , V_67 ) ;
F_18 ( V_2 -> V_19 , V_68 ) ;
F_18 ( V_2 -> V_19 , V_69 ) ;
F_18 ( V_2 -> V_19 , V_70 ) ;
F_7 ( V_2 -> V_19 -> V_71 ) ;
V_62 = F_19 ( V_2 -> V_19 ) ;
if ( V_62 != V_72 )
goto error;
for ( V_45 = 0 ; V_45 <= 64 ; V_45 ++ ) {
if ( F_45 ( V_2 -> V_19 ) )
goto error;
F_18 ( V_2 -> V_19 , V_73 ) ;
V_61 = F_27 ( V_2 -> V_19 , ( T_3 * ) & V_63 , 8 ) ;
V_65 = (struct V_64 * ) & V_63 ;
if ( V_65 -> V_51 == V_74 )
break;
if ( V_2 -> V_65 . V_75 == V_65 -> V_75 )
V_66 = V_45 ;
F_18 ( V_2 -> V_19 , V_68 ) ;
F_18 ( V_2 -> V_19 , V_76 ) ;
F_18 ( V_2 -> V_19 , V_77 ) ;
F_27 ( V_2 -> V_19 , & V_62 , sizeof( V_62 ) ) ;
V_62 = F_19 ( V_2 -> V_19 ) ;
if ( V_62 != V_72 )
goto error;
}
if ( F_45 ( V_2 -> V_19 ) )
goto error;
F_18 ( V_2 -> V_19 , V_67 ) ;
F_18 ( V_2 -> V_19 , V_68 ) ;
F_18 ( V_2 -> V_19 , V_78 ) ;
F_18 ( V_2 -> V_19 , V_79 ) ;
V_62 = F_19 ( V_2 -> V_19 ) ;
if ( V_62 != V_72 )
goto error;
F_21 ( & V_2 -> V_19 -> V_24 ) ;
V_58 -= snprintf ( V_49 + V_59 - V_58 , V_58 , L_11 , V_66 ) ;
return V_59 - V_58 ;
error:
F_21 ( & V_2 -> V_19 -> V_24 ) ;
return - V_60 ;
}
static int T_9 F_46 ( void )
{
int V_80 , V_45 ;
for ( V_45 = 0 ; V_45 < F_34 ( V_46 ) ; ++ V_45 ) {
V_80 = F_47 ( V_46 [ V_45 ] . V_47 ) ;
if ( V_80 )
V_46 [ V_45 ] . V_81 = 1 ;
}
return 0 ;
}
static void T_10 F_48 ( void )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < F_34 ( V_46 ) ; ++ V_45 )
if ( ! V_46 [ V_45 ] . V_81 )
F_49 ( V_46 [ V_45 ] . V_47 ) ;
}
