static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
F_2 ( V_6 -> V_8 . V_9 , 0x3d4 , V_4 -> V_10 + 1 ) ;
V_7 = F_3 ( V_6 -> V_8 . V_9 , 0x3d5 ) & 0xf0 ;
if ( V_2 )
V_7 |= 0x20 ;
else
V_7 &= ~ 0x20 ;
F_2 ( V_6 -> V_8 . V_9 , 0x3d4 , V_4 -> V_10 + 1 ) ;
F_2 ( V_6 -> V_8 . V_9 , 0x3d5 , V_7 | 0x1 ) ;
}
static void F_4 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
F_2 ( V_6 -> V_8 . V_9 , 0x3d4 , V_4 -> V_10 + 1 ) ;
V_7 = F_3 ( V_6 -> V_8 . V_9 , 0x3d5 ) & 0xf0 ;
if ( V_2 )
V_7 |= 0x10 ;
else
V_7 &= ~ 0x10 ;
F_2 ( V_6 -> V_8 . V_9 , 0x3d4 , V_4 -> V_10 + 1 ) ;
F_2 ( V_6 -> V_8 . V_9 , 0x3d5 , V_7 | 0x1 ) ;
}
static int F_5 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 = 0 ;
F_2 ( V_6 -> V_8 . V_9 , 0x3d4 , V_4 -> V_10 ) ;
if ( F_3 ( V_6 -> V_8 . V_9 , 0x3d5 ) & 0x04 )
V_7 = 1 ;
return V_7 ;
}
static int F_6 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 = 0 ;
F_2 ( V_6 -> V_8 . V_9 , 0x3d4 , V_4 -> V_10 ) ;
if ( F_3 ( V_6 -> V_8 . V_9 , 0x3d5 ) & 0x08 )
V_7 = 1 ;
return V_7 ;
}
static int T_2 F_7 ( struct V_3 * V_4 ,
const char * V_11 ,
unsigned int V_12 )
{
int V_13 ;
strcpy ( V_4 -> V_14 . V_11 , V_11 ) ;
V_4 -> V_14 . V_15 = V_16 ;
V_4 -> V_14 . V_17 = V_12 ;
V_4 -> V_14 . V_18 = & V_4 -> V_19 ;
V_4 -> V_14 . V_20 . V_21 = & V_4 -> V_6 -> V_22 -> V_20 ;
V_4 -> V_19 . V_23 = F_4 ;
V_4 -> V_19 . V_24 = F_1 ;
V_4 -> V_19 . V_25 = F_6 ;
V_4 -> V_19 . V_26 = F_5 ;
V_4 -> V_19 . V_27 = 40 ;
V_4 -> V_19 . V_28 = F_8 ( 2 ) ;
V_4 -> V_19 . V_1 = V_4 ;
F_9 ( & V_4 -> V_14 , V_4 ) ;
F_4 ( V_4 , 1 ) ;
F_1 ( V_4 , 1 ) ;
V_27 ( 20 ) ;
V_13 = F_10 ( & V_4 -> V_14 ) ;
if ( V_13 == 0 )
F_11 ( & V_4 -> V_6 -> V_22 -> V_20 , L_1 , V_11 ) ;
else {
F_12 ( & V_4 -> V_6 -> V_22 -> V_20 ,
L_2 , V_11 ) ;
V_4 -> V_6 = NULL ;
}
return V_13 ;
}
void T_2 F_13 ( struct V_5 * V_6 )
{
V_6 -> V_4 [ 0 ] . V_6 = V_6 ;
V_6 -> V_4 [ 1 ] . V_6 = V_6 ;
V_6 -> V_4 [ 2 ] . V_6 = V_6 ;
V_6 -> V_4 [ 0 ] . V_10 = 0x36 ;
V_6 -> V_4 [ 1 ] . V_10 = 0x3e ;
V_6 -> V_4 [ 2 ] . V_10 = 0x50 ;
F_7 ( & V_6 -> V_4 [ 0 ] , L_3 , V_29 ) ;
F_7 ( & V_6 -> V_4 [ 1 ] , L_4 , 0 ) ;
F_7 ( & V_6 -> V_4 [ 2 ] , L_5 , 0 ) ;
}
void F_14 ( struct V_5 * V_6 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < 3 ; V_30 ++ ) {
if ( ! V_6 -> V_4 [ V_30 ] . V_6 )
continue;
F_15 ( & V_6 -> V_4 [ V_30 ] . V_14 ) ;
V_6 -> V_4 [ V_30 ] . V_6 = NULL ;
}
}
int T_2 F_16 ( struct V_5 * V_6 , int V_31 , T_3 * * V_32 )
{
T_3 * V_33 = NULL ;
if ( V_6 -> V_4 [ V_31 ] . V_6 )
V_33 = F_17 ( & V_6 -> V_4 [ V_31 ] . V_14 ) ;
if ( V_32 )
* V_32 = V_33 ;
if ( ! V_33 )
return 1 ;
return 0 ;
}
