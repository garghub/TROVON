static inline T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
T_1 V_5 ;
T_1 * V_6 ;
V_6 = ( T_1 * ) ( V_7 +
F_2 ( V_2 -> V_8 , V_3 , V_4 & ~ 3 ) ) ;
V_5 = * V_6 ;
return F_3 ( V_5 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , T_1 V_5 )
{
T_1 * V_6 ;
V_6 = ( T_1 * ) ( V_7 +
F_2 ( V_2 -> V_8 , V_3 , V_4 & ~ 3 ) ) ;
* V_6 = F_3 ( V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_9 , T_1 * V_10 )
{
T_1 V_5 ;
if ( ( V_9 == 2 ) && ( V_4 & 1 ) )
return V_11 ;
else if ( ( V_9 == 4 ) && ( V_4 & 3 ) )
return V_11 ;
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_9 == 1 )
* V_10 = ( V_5 >> ( ( V_4 & 3 ) << 3 ) ) & 0xff ;
else if ( V_9 == 2 )
* V_10 = ( V_5 >> ( ( V_4 & 3 ) << 3 ) ) & 0xffff ;
else
* V_10 = V_5 ;
return V_12 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_9 , T_1 V_10 )
{
T_1 V_5 ;
if ( ( V_9 == 2 ) && ( V_4 & 1 ) )
return V_11 ;
else if ( ( V_9 == 4 ) && ( V_4 & 3 ) )
return V_11 ;
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_9 == 1 )
V_5 = ( V_5 & ~ ( 0xff << ( ( V_4 & 3 ) << 3 ) ) ) |
( V_10 << ( ( V_4 & 3 ) << 3 ) ) ;
else if ( V_9 == 2 )
V_5 = ( V_5 & ~ ( 0xffff << ( ( V_4 & 3 ) << 3 ) ) ) |
( V_10 << ( ( V_4 & 3 ) << 3 ) ) ;
else
V_5 = V_10 ;
F_4 ( V_2 , V_3 , V_4 , V_5 ) ;
return V_12 ;
}
static int F_7 ( const struct V_13 * V_14 )
{
if ( ! F_8 () )
return V_15 ;
if ( V_14 -> V_2 -> V_16 == NULL )
return 0 ;
switch ( V_14 -> V_2 -> V_16 -> V_3 ) {
case 0x0 :
return V_17 ;
case 0x8 :
return V_18 ;
case 0x10 :
if ( F_9 () )
return V_19 ;
else
return V_20 ;
case 0x18 :
if ( F_9 () )
return V_21 ;
else
return V_22 ;
}
F_10 ( 1 , L_1 , V_14 -> V_2 -> V_16 -> V_3 ) ;
return 0 ;
}
void F_11 ( unsigned int V_23 )
{
}
void F_12 ( unsigned int V_23 )
{
F_11 ( V_23 ) ;
}
int F_13 ( struct V_13 * V_14 , struct V_24 * V_25 )
{
struct V_26 V_27 ;
int V_23 , V_28 ;
V_23 = F_7 ( V_14 ) ;
if ( V_23 <= 0 )
return 1 ;
V_27 . V_29 = V_30 ;
V_27 . V_31 = V_32 |
V_33 |
V_34 ;
V_27 . V_5 = V_35 |
V_36 |
V_37 ;
V_28 = F_14 ( V_23 , V_25 ) ;
if ( V_28 < 0 ) {
F_11 ( V_23 ) ;
return V_28 ;
}
F_15 ( V_23 , & V_27 ) ;
return 0 ;
}
static void F_16 ( struct V_38 * V_39 )
{
T_2 V_40 = F_17 ( V_41 ) ;
F_18 ( V_40 , ( 0x140 >> 2 ) ) ;
}
static void F_19 ( struct V_38 * V_39 )
{
T_2 V_42 = F_17 ( V_43 ) ;
switch ( V_39 -> V_23 ) {
case V_17 :
F_20 ( V_42 , ( 0x90 >> 2 ) , 0xffffffff ) ;
break;
case V_18 :
F_20 ( V_42 , ( 0x94 >> 2 ) , 0xffffffff ) ;
break;
case V_20 :
F_20 ( V_42 , ( 0x190 >> 2 ) , 0xffffffff ) ;
break;
case V_22 :
F_20 ( V_42 , ( 0x194 >> 2 ) , 0xffffffff ) ;
break;
}
}
static void F_21 ( struct V_38 * V_39 )
{
T_2 V_42 = F_17 ( V_43 ) ;
switch ( V_39 -> V_23 ) {
case V_17 :
F_20 ( V_42 , ( 0x90 >> 2 ) , 0xffffffff ) ;
break;
case V_18 :
F_20 ( V_42 , ( 0x94 >> 2 ) , 0xffffffff ) ;
break;
case V_19 :
F_20 ( V_42 , ( 0x190 >> 2 ) , 0xffffffff ) ;
break;
case V_21 :
F_20 ( V_42 , ( 0x194 >> 2 ) , 0xffffffff ) ;
break;
}
}
int T_3 F_22 ( const struct V_13 * V_14 , T_4 V_44 , T_4 V_45 )
{
return F_7 ( V_14 ) ;
}
int F_23 ( struct V_13 * V_14 )
{
return 0 ;
}
static int T_3 F_24 ( void )
{
F_25 ( V_46 ) ;
V_7 = F_26 ( V_47 , 16 << 20 ) ;
V_48 . V_49 = 0 ;
V_48 . V_50 = ~ 0 ;
F_27 ( V_51 ) ;
V_52 . V_53 = V_51 ;
F_28 ( L_2 ) ;
F_29 ( & V_52 ) ;
if ( F_8 () ) {
if ( F_9 () ) {
F_30 ( V_17 ,
F_21 ) ;
F_30 ( V_18 ,
F_21 ) ;
F_30 ( V_19 ,
F_21 ) ;
F_30 ( V_21 ,
F_21 ) ;
} else {
F_30 ( V_17 , F_19 ) ;
F_30 ( V_18 , F_19 ) ;
F_30 ( V_20 , F_19 ) ;
F_30 ( V_22 , F_19 ) ;
}
} else {
F_30 ( V_21 , F_16 ) ;
}
return 0 ;
}
