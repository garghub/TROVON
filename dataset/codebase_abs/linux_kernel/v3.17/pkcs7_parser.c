void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( V_2 ) {
while ( V_2 -> V_7 ) {
V_4 = V_2 -> V_7 ;
V_2 -> V_7 = V_4 -> V_8 ;
F_2 ( V_4 ) ;
}
while ( V_2 -> V_9 ) {
V_4 = V_2 -> V_9 ;
V_2 -> V_9 = V_4 -> V_8 ;
F_2 ( V_4 ) ;
}
while ( V_2 -> V_10 ) {
V_6 = V_2 -> V_10 ;
V_2 -> V_10 = V_6 -> V_8 ;
F_3 ( V_6 -> V_11 . V_12 [ 0 ] ) ;
F_4 ( V_6 -> V_11 . V_13 ) ;
F_4 ( V_6 ) ;
}
F_4 ( V_2 ) ;
}
}
struct V_1 * F_5 ( const void * V_14 , T_1 V_15 )
{
struct V_16 * V_17 ;
struct V_1 * V_18 ;
long V_19 ;
V_19 = - V_20 ;
V_18 = F_6 ( sizeof( struct V_1 ) , V_21 ) ;
if ( ! V_18 )
goto V_22;
V_17 = F_6 ( sizeof( struct V_16 ) , V_21 ) ;
if ( ! V_17 )
goto V_23;
V_17 -> V_6 = F_6 ( sizeof( struct V_5 ) , V_21 ) ;
if ( ! V_17 -> V_6 )
goto V_24;
V_17 -> V_18 = V_18 ;
V_17 -> V_14 = ( unsigned long ) V_14 ;
V_17 -> V_25 = & V_17 -> V_7 ;
V_17 -> V_26 = & V_17 -> V_18 -> V_10 ;
V_19 = F_7 ( & V_27 , V_17 , V_14 , V_15 ) ;
if ( V_19 < 0 )
goto V_28;
while ( V_17 -> V_7 ) {
struct V_3 * V_4 = V_17 -> V_7 ;
V_17 -> V_7 = V_4 -> V_8 ;
F_2 ( V_4 ) ;
}
F_3 ( V_17 -> V_6 -> V_11 . V_12 [ 0 ] ) ;
F_4 ( V_17 -> V_6 -> V_11 . V_13 ) ;
F_4 ( V_17 -> V_6 ) ;
F_4 ( V_17 ) ;
return V_18 ;
V_28:
F_3 ( V_17 -> V_6 -> V_11 . V_12 [ 0 ] ) ;
F_4 ( V_17 -> V_6 -> V_11 . V_13 ) ;
F_4 ( V_17 -> V_6 ) ;
V_24:
F_4 ( V_17 ) ;
V_23:
F_1 ( V_18 ) ;
V_22:
return F_8 ( V_19 ) ;
}
int F_9 ( const struct V_1 * V_2 ,
const void * * V_29 , T_1 * V_30 ,
bool V_31 )
{
T_1 V_32 ;
if ( ! V_2 -> V_14 )
return - V_33 ;
V_32 = V_31 ? V_2 -> V_34 : 0 ;
* V_29 = V_2 -> V_14 - V_32 ;
* V_30 = V_2 -> V_35 + V_32 ;
return 0 ;
}
int F_10 ( void * V_36 , T_1 V_37 ,
unsigned char V_38 ,
const void * V_39 , T_1 V_40 )
{
struct V_16 * V_17 = V_36 ;
V_17 -> V_41 = F_11 ( V_39 , V_40 ) ;
if ( V_17 -> V_41 == V_42 ) {
char V_43 [ 50 ] ;
F_12 ( V_39 , V_40 , V_43 , sizeof( V_43 ) ) ;
F_13 ( L_1 ,
( unsigned long ) V_39 - V_17 -> V_14 , V_43 ) ;
}
return 0 ;
}
int F_14 ( void * V_36 , T_1 V_37 ,
unsigned char V_38 ,
const void * V_39 , T_1 V_40 )
{
struct V_16 * V_17 = V_36 ;
switch ( V_17 -> V_41 ) {
case V_44 :
V_17 -> V_6 -> V_11 . V_45 = V_46 ;
break;
case V_47 :
V_17 -> V_6 -> V_11 . V_45 = V_48 ;
break;
case V_49 :
V_17 -> V_6 -> V_11 . V_45 = V_50 ;
break;
case V_51 :
V_17 -> V_6 -> V_11 . V_45 = V_52 ;
break;
default:
F_13 ( L_2 , V_17 -> V_41 ) ;
return - V_53 ;
}
return 0 ;
}
int F_15 ( void * V_36 , T_1 V_37 ,
unsigned char V_38 ,
const void * V_39 , T_1 V_40 )
{
struct V_16 * V_17 = V_36 ;
switch ( V_17 -> V_41 ) {
case V_54 :
V_17 -> V_6 -> V_11 . V_55 = V_56 ;
break;
default:
F_13 ( L_3 , V_17 -> V_41 ) ;
return - V_53 ;
}
return 0 ;
}
int F_16 ( void * V_36 , T_1 V_37 ,
unsigned char V_38 ,
const void * V_39 , T_1 V_40 )
{
struct V_16 * V_17 = V_36 ;
struct V_3 * V_57 ;
if ( V_38 != ( ( V_58 << 6 ) | V_59 | V_60 ) ) {
F_17 ( L_4 ,
V_38 , ( unsigned long ) V_17 - V_17 -> V_14 ) ;
return - V_61 ;
}
V_39 -= V_37 ;
V_40 += V_37 ;
if ( ( ( V_62 * ) V_39 ) [ 1 ] == 0x80 )
V_40 += 2 ;
V_57 = F_18 ( V_39 , V_40 ) ;
if ( F_19 ( V_57 ) )
return F_20 ( V_57 ) ;
F_17 ( L_5 , V_57 -> V_63 ) ;
F_17 ( L_6 , V_57 -> V_64 ) ;
V_57 -> V_65 = ++ V_17 -> V_66 ;
* V_17 -> V_25 = V_57 ;
V_17 -> V_25 = & V_57 -> V_8 ;
return 0 ;
}
int F_21 ( void * V_36 , T_1 V_37 ,
unsigned char V_38 ,
const void * V_39 , T_1 V_40 )
{
struct V_16 * V_17 = V_36 ;
F_22 ( L_7 , V_38 ) ;
* V_17 -> V_25 = V_17 -> V_18 -> V_7 ;
V_17 -> V_18 -> V_7 = V_17 -> V_7 ;
V_17 -> V_7 = NULL ;
V_17 -> V_25 = & V_17 -> V_7 ;
return 0 ;
}
int F_23 ( void * V_36 , T_1 V_37 ,
unsigned char V_38 ,
const void * V_39 , T_1 V_40 )
{
struct V_16 * V_17 = V_36 ;
F_17 ( L_8 ) ;
V_17 -> V_18 -> V_14 = V_39 ;
V_17 -> V_18 -> V_35 = V_40 ;
V_17 -> V_18 -> V_34 = V_37 ;
V_17 -> V_18 -> V_67 = V_17 -> V_41 ;
return 0 ;
}
int F_24 ( void * V_36 , T_1 V_37 ,
unsigned char V_38 ,
const void * V_39 , T_1 V_40 )
{
struct V_16 * V_17 = V_36 ;
F_22 ( L_9 , V_38 , V_40 , ( unsigned ) V_40 , V_39 ) ;
switch ( V_17 -> V_41 ) {
case V_68 :
if ( V_38 != V_69 )
return - V_61 ;
V_17 -> V_6 -> V_70 = V_39 ;
V_17 -> V_6 -> V_71 = V_40 ;
return 0 ;
default:
return 0 ;
}
}
int F_25 ( void * V_36 , T_1 V_37 ,
unsigned char V_38 ,
const void * V_39 , T_1 V_40 )
{
struct V_16 * V_17 = V_36 ;
V_17 -> V_6 -> V_72 = V_39 - ( V_37 - 1 ) ;
V_17 -> V_6 -> V_73 = V_40 + ( V_37 - 1 ) ;
return 0 ;
}
int F_26 ( void * V_36 , T_1 V_37 ,
unsigned char V_38 ,
const void * V_39 , T_1 V_40 )
{
struct V_16 * V_17 = V_36 ;
V_17 -> V_6 -> V_74 = V_39 ;
V_17 -> V_6 -> V_75 = V_40 ;
return 0 ;
}
int F_27 ( void * V_36 , T_1 V_37 ,
unsigned char V_38 ,
const void * V_39 , T_1 V_40 )
{
struct V_16 * V_17 = V_36 ;
V_17 -> V_6 -> V_76 = V_39 ;
V_17 -> V_6 -> V_77 = V_40 ;
return 0 ;
}
int F_28 ( void * V_36 , T_1 V_37 ,
unsigned char V_38 ,
const void * V_39 , T_1 V_40 )
{
struct V_16 * V_17 = V_36 ;
T_2 V_12 ;
F_29 ( V_17 -> V_6 -> V_11 . V_55 != V_56 ) ;
V_12 = F_30 ( V_39 , V_40 ) ;
if ( ! V_12 )
return - V_20 ;
V_17 -> V_6 -> V_11 . V_12 [ 0 ] = V_12 ;
V_17 -> V_6 -> V_11 . V_78 = 1 ;
return 0 ;
}
int F_31 ( void * V_36 , T_1 V_37 ,
unsigned char V_38 ,
const void * V_39 , T_1 V_40 )
{
struct V_16 * V_17 = V_36 ;
V_17 -> V_6 -> V_65 = ++ V_17 -> V_79 ;
* V_17 -> V_26 = V_17 -> V_6 ;
V_17 -> V_26 = & V_17 -> V_6 -> V_8 ;
V_17 -> V_6 = F_6 ( sizeof( struct V_5 ) , V_21 ) ;
if ( ! V_17 -> V_6 )
return - V_20 ;
return 0 ;
}
