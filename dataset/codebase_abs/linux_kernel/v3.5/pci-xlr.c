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
static struct V_13 * F_7 ( const struct V_13 * V_14 )
{
struct V_1 * V_2 , * V_15 ;
V_2 = V_14 -> V_2 ;
for ( V_15 = V_2 -> V_16 ; V_15 && V_15 -> V_8 != 0 ; V_15 = V_15 -> V_16 )
V_2 = V_15 ;
return V_15 ? V_2 -> V_17 : NULL ;
}
static int F_8 ( const struct V_13 * V_14 )
{
struct V_13 * V_18 ;
if ( ! F_9 () )
return V_19 ;
V_18 = F_7 ( V_14 ) ;
if ( V_18 == NULL )
return 0 ;
switch ( F_10 ( V_18 -> V_3 ) ) {
case 0 :
return V_20 ;
case 1 :
return V_21 ;
case 2 :
if ( F_11 () )
return V_22 ;
else
return V_23 ;
case 3 :
if ( F_11 () )
return V_24 ;
else
return V_25 ;
}
F_12 ( 1 , L_1 , V_18 -> V_3 ) ;
return 0 ;
}
void F_13 ( unsigned int V_26 )
{
}
void F_14 ( unsigned int V_26 )
{
F_13 ( V_26 ) ;
}
int F_15 ( struct V_13 * V_14 , struct V_27 * V_28 )
{
struct V_29 V_30 ;
struct V_13 * V_18 ;
int V_26 , V_31 ;
T_2 V_10 ;
if ( ! F_9 () )
return 1 ;
V_18 = F_7 ( V_14 ) ;
if ( V_18 == NULL )
return 1 ;
F_16 ( V_18 , 0x50 + V_32 , & V_10 ) ;
if ( ( V_10 & V_33 ) == 0 ) {
V_10 |= V_33 ;
F_17 ( V_18 , 0x50 + V_32 , V_10 ) ;
}
V_26 = F_8 ( V_14 ) ;
if ( V_26 <= 0 )
return 1 ;
V_30 . V_34 = V_35 ;
V_30 . V_36 = V_37 |
V_38 |
V_39 ;
V_30 . V_5 = V_40 |
V_41 |
V_42 ;
V_31 = F_18 ( V_26 , V_28 ) ;
if ( V_31 < 0 ) {
F_13 ( V_26 ) ;
return V_31 ;
}
F_19 ( V_26 , & V_30 ) ;
return 0 ;
}
static void F_20 ( struct V_43 * V_44 )
{
T_3 V_45 = F_21 ( V_46 ) ;
F_22 ( V_45 , ( 0x140 >> 2 ) ) ;
}
static void F_23 ( struct V_43 * V_44 )
{
T_3 V_47 = F_21 ( V_48 ) ;
switch ( V_44 -> V_26 ) {
case V_20 :
F_24 ( V_47 , ( 0x90 >> 2 ) , 0xffffffff ) ;
break;
case V_21 :
F_24 ( V_47 , ( 0x94 >> 2 ) , 0xffffffff ) ;
break;
case V_23 :
F_24 ( V_47 , ( 0x190 >> 2 ) , 0xffffffff ) ;
break;
case V_25 :
F_24 ( V_47 , ( 0x194 >> 2 ) , 0xffffffff ) ;
break;
}
}
static void F_25 ( struct V_43 * V_44 )
{
T_3 V_47 = F_21 ( V_48 ) ;
switch ( V_44 -> V_26 ) {
case V_20 :
F_24 ( V_47 , ( 0x90 >> 2 ) , 0xffffffff ) ;
break;
case V_21 :
F_24 ( V_47 , ( 0x94 >> 2 ) , 0xffffffff ) ;
break;
case V_22 :
F_24 ( V_47 , ( 0x190 >> 2 ) , 0xffffffff ) ;
break;
case V_24 :
F_24 ( V_47 , ( 0x194 >> 2 ) , 0xffffffff ) ;
break;
}
}
int T_4 F_26 ( const struct V_13 * V_14 , T_5 V_49 , T_5 V_50 )
{
return F_8 ( V_14 ) ;
}
int F_27 ( struct V_13 * V_14 )
{
return 0 ;
}
static int T_4 F_28 ( void )
{
F_29 ( V_51 ) ;
V_7 = F_30 ( V_52 , 16 << 20 ) ;
V_53 . V_54 = 0 ;
V_53 . V_55 = ~ 0 ;
F_31 ( V_56 ) ;
V_57 . V_58 = V_56 ;
F_32 ( L_2 ) ;
F_33 ( & V_57 ) ;
if ( F_9 () ) {
if ( F_11 () ) {
F_34 ( V_20 ,
F_25 ) ;
F_34 ( V_21 ,
F_25 ) ;
F_34 ( V_22 ,
F_25 ) ;
F_34 ( V_24 ,
F_25 ) ;
} else {
F_34 ( V_20 , F_23 ) ;
F_34 ( V_21 , F_23 ) ;
F_34 ( V_23 , F_23 ) ;
F_34 ( V_25 , F_23 ) ;
}
} else {
F_34 ( V_19 , F_20 ) ;
}
return 0 ;
}
