static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_2 ( V_2 -> V_3 . V_4 [ 0 ] ) ;
F_3 ( V_2 -> V_3 . V_5 ) ;
F_3 ( V_2 -> V_6 ) ;
F_3 ( V_2 ) ;
}
}
void F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
if ( V_8 ) {
while ( V_8 -> V_11 ) {
V_10 = V_8 -> V_11 ;
V_8 -> V_11 = V_10 -> V_12 ;
F_5 ( V_10 ) ;
}
while ( V_8 -> V_13 ) {
V_10 = V_8 -> V_13 ;
V_8 -> V_13 = V_10 -> V_12 ;
F_5 ( V_10 ) ;
}
while ( V_8 -> V_14 ) {
V_2 = V_8 -> V_14 ;
V_8 -> V_14 = V_2 -> V_12 ;
F_1 ( V_2 ) ;
}
F_3 ( V_8 ) ;
}
}
struct V_7 * F_6 ( const void * V_15 , T_1 V_16 )
{
struct V_17 * V_18 ;
struct V_7 * V_19 = F_7 ( - V_20 ) ;
int V_21 ;
V_18 = F_8 ( sizeof( struct V_17 ) , V_22 ) ;
if ( ! V_18 )
goto V_23;
V_18 -> V_19 = F_8 ( sizeof( struct V_7 ) , V_22 ) ;
if ( ! V_18 -> V_19 )
goto V_24;
V_18 -> V_2 = F_8 ( sizeof( struct V_1 ) , V_22 ) ;
if ( ! V_18 -> V_2 )
goto V_25;
V_18 -> V_15 = ( unsigned long ) V_15 ;
V_18 -> V_26 = & V_18 -> V_11 ;
V_18 -> V_27 = & V_18 -> V_19 -> V_14 ;
V_21 = F_9 ( & V_28 , V_18 , V_15 , V_16 ) ;
if ( V_21 < 0 ) {
V_19 = F_7 ( V_21 ) ;
goto V_29;
}
V_19 = V_18 -> V_19 ;
V_18 -> V_19 = NULL ;
V_29:
while ( V_18 -> V_11 ) {
struct V_9 * V_10 = V_18 -> V_11 ;
V_18 -> V_11 = V_10 -> V_12 ;
F_5 ( V_10 ) ;
}
F_1 ( V_18 -> V_2 ) ;
V_25:
F_4 ( V_18 -> V_19 ) ;
V_24:
F_3 ( V_18 ) ;
V_23:
return V_19 ;
}
int F_10 ( const struct V_7 * V_8 ,
const void * * V_30 , T_1 * V_31 ,
bool V_32 )
{
T_1 V_33 ;
if ( ! V_8 -> V_15 )
return - V_34 ;
V_33 = V_32 ? V_8 -> V_35 : 0 ;
* V_30 = V_8 -> V_15 - V_33 ;
* V_31 = V_8 -> V_36 + V_33 ;
return 0 ;
}
int F_11 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_17 * V_18 = V_37 ;
V_18 -> V_42 = F_12 ( V_40 , V_41 ) ;
if ( V_18 -> V_42 == V_43 ) {
char V_44 [ 50 ] ;
F_13 ( V_40 , V_41 , V_44 , sizeof( V_44 ) ) ;
F_14 ( L_1 ,
( unsigned long ) V_40 - V_18 -> V_15 , V_44 ) ;
}
return 0 ;
}
int F_15 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_17 * V_18 = V_37 ;
switch ( V_18 -> V_42 ) {
case V_45 :
V_18 -> V_2 -> V_3 . V_46 = V_47 ;
break;
case V_48 :
V_18 -> V_2 -> V_3 . V_46 = V_49 ;
break;
case V_50 :
V_18 -> V_2 -> V_3 . V_46 = V_51 ;
break;
case V_52 :
V_18 -> V_2 -> V_3 . V_46 = V_53 ;
break;
default:
F_14 ( L_2 , V_18 -> V_42 ) ;
return - V_54 ;
}
return 0 ;
}
int F_16 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_17 * V_18 = V_37 ;
switch ( V_18 -> V_42 ) {
case V_55 :
V_18 -> V_2 -> V_3 . V_56 = V_57 ;
break;
default:
F_14 ( L_3 , V_18 -> V_42 ) ;
return - V_54 ;
}
return 0 ;
}
int F_17 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_17 * V_18 = V_37 ;
struct V_9 * V_58 ;
if ( V_39 != ( ( V_59 << 6 ) | V_60 | V_61 ) ) {
F_18 ( L_4 ,
V_39 , ( unsigned long ) V_18 - V_18 -> V_15 ) ;
return - V_62 ;
}
V_40 -= V_38 ;
V_41 += V_38 ;
if ( ( ( V_63 * ) V_40 ) [ 1 ] == 0x80 )
V_41 += 2 ;
V_58 = F_19 ( V_40 , V_41 ) ;
if ( F_20 ( V_58 ) )
return F_21 ( V_58 ) ;
V_58 -> V_64 = ++ V_18 -> V_65 ;
F_18 ( L_5 , V_58 -> V_64 , V_58 -> V_66 ) ;
F_18 ( L_6 , V_58 -> V_67 -> V_68 , V_58 -> V_67 -> V_15 ) ;
* V_18 -> V_26 = V_58 ;
V_18 -> V_26 = & V_58 -> V_12 ;
return 0 ;
}
int F_22 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_17 * V_18 = V_37 ;
F_23 ( L_7 , V_39 ) ;
* V_18 -> V_26 = V_18 -> V_19 -> V_11 ;
V_18 -> V_19 -> V_11 = V_18 -> V_11 ;
V_18 -> V_11 = NULL ;
V_18 -> V_26 = & V_18 -> V_11 ;
return 0 ;
}
int F_24 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_17 * V_18 = V_37 ;
F_18 ( L_8 ) ;
V_18 -> V_19 -> V_15 = V_40 ;
V_18 -> V_19 -> V_36 = V_41 ;
V_18 -> V_19 -> V_35 = V_38 ;
V_18 -> V_19 -> V_69 = V_18 -> V_42 ;
return 0 ;
}
int F_25 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_17 * V_18 = V_37 ;
F_23 ( L_9 , V_39 , V_41 , ( unsigned ) V_41 , V_40 ) ;
switch ( V_18 -> V_42 ) {
case V_70 :
if ( V_39 != V_71 )
return - V_62 ;
V_18 -> V_2 -> V_72 = V_40 ;
V_18 -> V_2 -> V_73 = V_41 ;
return 0 ;
default:
return 0 ;
}
}
int F_26 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_17 * V_18 = V_37 ;
V_18 -> V_2 -> V_74 = V_40 - ( V_38 - 1 ) ;
V_18 -> V_2 -> V_75 = V_41 + ( V_38 - 1 ) ;
return 0 ;
}
int F_27 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_17 * V_18 = V_37 ;
V_18 -> V_76 = V_40 ;
V_18 -> V_77 = V_41 ;
return 0 ;
}
int F_28 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_17 * V_18 = V_37 ;
V_18 -> V_78 = V_40 ;
V_18 -> V_79 = V_41 ;
return 0 ;
}
int F_29 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_17 * V_18 = V_37 ;
T_2 V_4 ;
F_30 ( V_18 -> V_2 -> V_3 . V_56 != V_57 ) ;
V_4 = F_31 ( V_40 , V_41 ) ;
if ( ! V_4 )
return - V_20 ;
V_18 -> V_2 -> V_3 . V_4 [ 0 ] = V_4 ;
V_18 -> V_2 -> V_3 . V_80 = 1 ;
return 0 ;
}
int F_32 ( void * V_37 , T_1 V_38 ,
unsigned char V_39 ,
const void * V_40 , T_1 V_41 )
{
struct V_17 * V_18 = V_37 ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_81 * V_82 ;
V_82 = F_33 ( V_18 -> V_76 ,
V_18 -> V_77 ,
V_18 -> V_78 ,
V_18 -> V_79 ) ;
if ( F_20 ( V_82 ) )
return F_21 ( V_82 ) ;
V_2 -> V_6 = V_82 ;
V_2 -> V_64 = ++ V_18 -> V_83 ;
* V_18 -> V_27 = V_2 ;
V_18 -> V_27 = & V_2 -> V_12 ;
V_18 -> V_2 = F_8 ( sizeof( struct V_1 ) , V_22 ) ;
if ( ! V_18 -> V_2 )
return - V_20 ;
return 0 ;
}
