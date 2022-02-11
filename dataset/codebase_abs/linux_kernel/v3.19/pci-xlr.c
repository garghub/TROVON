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
static int F_8 ( int V_18 )
{
switch ( V_18 ) {
case 0 :
return V_19 ;
case 1 :
return V_20 ;
case 2 :
if ( F_9 () )
return V_21 ;
else
return V_22 ;
case 3 :
if ( F_9 () )
return V_23 ;
else
return V_24 ;
}
F_10 ( 1 , L_1 , V_18 ) ;
return 0 ;
}
static int F_11 ( const struct V_13 * V_14 )
{
struct V_13 * V_25 ;
int V_18 ;
if ( ! F_12 () )
return V_26 ;
V_25 = F_7 ( V_14 ) ;
if ( V_25 == NULL )
return 0 ;
V_18 = F_13 ( V_25 -> V_3 ) ;
return F_8 ( V_18 ) ;
}
void F_14 ( unsigned int V_27 )
{
}
int F_15 ( struct V_13 * V_14 , struct V_28 * V_29 )
{
struct V_30 V_31 ;
struct V_13 * V_25 ;
int V_27 , V_32 ;
T_2 V_10 ;
if ( ! F_12 () )
return 1 ;
V_25 = F_7 ( V_14 ) ;
if ( V_25 == NULL )
return 1 ;
F_16 ( V_25 , 0x50 + V_33 , & V_10 ) ;
if ( ( V_10 & V_34 ) == 0 ) {
V_10 |= V_34 ;
F_17 ( V_25 , 0x50 + V_33 , V_10 ) ;
}
V_27 = F_11 ( V_14 ) ;
if ( V_27 <= 0 )
return 1 ;
V_31 . V_35 = V_36 ;
V_31 . V_37 = V_38 |
V_39 |
V_40 ;
V_31 . V_5 = V_41 |
V_42 |
V_43 ;
V_32 = F_18 ( V_27 , V_29 ) ;
if ( V_32 < 0 )
return V_32 ;
F_19 ( V_27 , & V_31 ) ;
return 0 ;
}
static void F_20 ( struct V_44 * V_45 )
{
T_3 V_46 = F_21 ( V_47 ) ;
F_22 ( V_46 , ( 0x140 >> 2 ) ) ;
}
static void F_23 ( struct V_44 * V_45 )
{
T_3 V_48 = F_21 ( V_49 ) ;
switch ( V_45 -> V_27 ) {
case V_19 :
F_24 ( V_48 , ( 0x90 >> 2 ) , 0xffffffff ) ;
break;
case V_20 :
F_24 ( V_48 , ( 0x94 >> 2 ) , 0xffffffff ) ;
break;
case V_22 :
F_24 ( V_48 , ( 0x190 >> 2 ) , 0xffffffff ) ;
break;
case V_24 :
F_24 ( V_48 , ( 0x194 >> 2 ) , 0xffffffff ) ;
break;
}
}
static void F_25 ( struct V_44 * V_45 )
{
T_3 V_48 = F_21 ( V_49 ) ;
switch ( V_45 -> V_27 ) {
case V_19 :
F_24 ( V_48 , ( 0x90 >> 2 ) , 0xffffffff ) ;
break;
case V_20 :
F_24 ( V_48 , ( 0x94 >> 2 ) , 0xffffffff ) ;
break;
case V_21 :
F_24 ( V_48 , ( 0x190 >> 2 ) , 0xffffffff ) ;
break;
case V_23 :
F_24 ( V_48 , ( 0x194 >> 2 ) , 0xffffffff ) ;
break;
}
}
int T_4 F_26 ( const struct V_13 * V_14 , T_5 V_50 , T_5 V_51 )
{
return F_11 ( V_14 ) ;
}
int F_27 ( struct V_13 * V_14 )
{
return 0 ;
}
static int T_4 F_28 ( void )
{
void (* F_29)( struct V_44 * );
int V_18 , V_27 ;
F_30 ( V_52 ) ;
V_7 = F_31 ( V_53 , 16 << 20 ) ;
V_54 . V_55 = 0 ;
V_54 . V_56 = ~ 0 ;
F_32 ( V_57 ) ;
V_58 . V_59 = V_57 ;
F_33 ( L_2 ) ;
F_34 ( & V_58 ) ;
if ( ! F_12 () ) {
F_35 ( 0 , V_26 , F_20 ) ;
} else {
if ( F_9 () )
F_29 = F_25 ;
else
F_29 = F_23 ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
V_27 = F_8 ( V_18 ) ;
F_35 ( 0 , V_27 , F_29 ) ;
}
}
return 0 ;
}
