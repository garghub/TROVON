int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
F_2 ( V_2 ) ;
V_4 = F_3 ( V_2 , V_5 ) ;
F_4 ( V_2 ) ;
return V_4 ;
}
static int F_5 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
V_9 -> type = V_10 ;
V_9 -> V_11 = 2 ;
V_9 -> V_12 . integer . V_13 = 0 ;
V_9 -> V_12 . integer . V_14 = 43 ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_7 ) ;
F_2 ( V_18 -> V_2 ) ;
V_16 -> V_12 . integer . V_12 [ 0 ] = V_18 -> V_19 - 0x14 ;
V_16 -> V_12 . integer . V_12 [ 1 ] = V_18 -> V_20 - 0x14 ;
F_4 ( V_18 -> V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_7 ) ;
int V_21 , V_11 , V_22 ;
unsigned char V_23 [ 3 ] ;
unsigned char V_24 , V_25 ;
V_24 = ( V_16 -> V_12 . integer . V_12 [ 0 ] % 44 ) + 0x14 ;
V_25 = ( V_16 -> V_12 . integer . V_12 [ 1 ] % 44 ) + 0x14 ;
F_2 ( V_18 -> V_2 ) ;
V_21 = V_24 != V_18 -> V_19 || V_25 != V_18 -> V_20 ;
V_18 -> V_19 = V_24 ;
V_18 -> V_20 = V_25 ;
V_11 = 0 ;
if ( V_18 -> V_26 [ V_27 ] != 0 ) {
V_23 [ V_11 ++ ] = V_27 ;
V_23 [ V_11 ++ ] = V_18 -> V_26 [ V_27 ] = V_18 -> V_19 ;
}
if ( V_18 -> V_26 [ V_28 ] != 0 ) {
if ( V_11 == 0 )
V_23 [ V_11 ++ ] = V_28 ;
V_23 [ V_11 ++ ] = V_18 -> V_26 [ V_28 ] = V_18 -> V_20 ;
}
if ( V_11 > 0 ) {
if ( ( V_22 = F_9 ( V_18 -> V_29 , V_23 , V_11 ) ) < 0 )
V_21 = V_22 ;
}
F_4 ( V_18 -> V_2 ) ;
return V_21 ;
}
static int F_10 ( struct V_6 * V_7 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_7 ) ;
F_2 ( V_18 -> V_2 ) ;
V_16 -> V_12 . integer . V_12 [ 0 ] = V_18 -> V_26 [ V_27 ] == 0 ? 0 : 1 ;
V_16 -> V_12 . integer . V_12 [ 1 ] = V_18 -> V_26 [ V_28 ] == 0 ? 0 : 1 ;
F_4 ( V_18 -> V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_7 ) ;
int V_21 , V_22 ;
unsigned char V_23 [ 3 ] ;
unsigned char V_30 , V_31 , V_24 , V_25 ;
V_24 = V_16 -> V_12 . integer . V_12 [ 0 ] & 1 ;
V_25 = V_16 -> V_12 . integer . V_12 [ 1 ] & 1 ;
F_2 ( V_18 -> V_2 ) ;
V_30 = V_18 -> V_26 [ V_27 ] == 0 ? 0 : 1 ;
V_31 = V_18 -> V_26 [ V_28 ] == 0 ? 0 : 1 ;
V_21 = V_24 != V_30 || V_25 != V_31 ;
V_18 -> V_26 [ V_27 ] = V_24 ? V_18 -> V_19 : 0 ;
V_18 -> V_26 [ V_28 ] = V_25 ? V_18 -> V_20 : 0 ;
V_23 [ 0 ] = V_27 ;
V_23 [ 1 ] = V_18 -> V_26 [ V_27 ] ;
V_23 [ 2 ] = V_18 -> V_26 [ V_28 ] ;
if ( ( V_22 = F_9 ( V_18 -> V_29 , V_23 , 3 ) ) < 0 )
V_21 = V_22 ;
F_4 ( V_18 -> V_2 ) ;
return V_21 ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_17 * V_18 = F_7 ( V_7 ) ;
V_9 -> type = V_10 ;
V_9 -> V_11 = 1 ;
V_9 -> V_12 . integer . V_13 = 0 ;
V_9 -> V_12 . integer . V_14 = V_18 -> V_32 ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_7 ) ;
V_16 -> V_12 . integer . V_12 [ 0 ] = V_18 -> V_33 ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_7 ) ;
int V_21 , V_22 ;
unsigned char V_23 [ 2 ] ;
unsigned char V_24 ;
V_24 = V_16 -> V_12 . integer . V_12 [ 0 ] % ( V_18 -> V_32 + 1 ) ;
F_2 ( V_18 -> V_2 ) ;
V_18 -> V_33 = V_24 ;
V_24 += V_18 -> V_3 ? 7 : 3 ;
V_21 = V_18 -> V_26 [ V_34 ] != V_24 ;
V_23 [ 0 ] = V_34 ;
V_23 [ 1 ] = V_18 -> V_26 [ V_34 ] = V_24 ;
if ( ( V_22 = F_9 ( V_18 -> V_29 , V_23 , 2 ) ) < 0 )
V_21 = V_22 ;
F_4 ( V_18 -> V_2 ) ;
return V_21 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_17 * V_18 = F_7 ( V_7 ) ;
V_9 -> type = V_10 ;
V_9 -> V_11 = 1 ;
V_9 -> V_12 . integer . V_13 = 0 ;
V_9 -> V_12 . integer . V_14 = V_18 -> V_35 ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_7 ) ;
V_16 -> V_12 . integer . V_12 [ 0 ] = V_18 -> V_36 ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_7 ) ;
int V_21 , V_22 ;
unsigned char V_23 [ 2 ] ;
unsigned char V_24 ;
V_24 = V_16 -> V_12 . integer . V_12 [ 0 ] % ( V_18 -> V_35 + 1 ) ;
F_2 ( V_18 -> V_2 ) ;
V_18 -> V_36 = V_24 ;
V_24 += 3 ;
V_21 = V_18 -> V_26 [ V_37 ] != V_24 ;
V_23 [ 0 ] = V_37 ;
V_23 [ 1 ] = V_18 -> V_26 [ V_37 ] = V_24 ;
if ( ( V_22 = F_9 ( V_18 -> V_29 , V_23 , 2 ) ) < 0 )
V_21 = V_22 ;
F_4 ( V_18 -> V_2 ) ;
return V_21 ;
}
static void F_18 ( struct V_38 * V_29 )
{
F_19 ( V_29 -> V_39 ) ;
}
int F_20 ( struct V_40 * V_41 ,
struct V_1 * V_2 ,
int V_3 , int V_42 )
{
struct V_38 * V_29 ;
struct V_17 * V_18 ;
struct V_43 * V_44 ;
unsigned int V_45 ;
int V_22 = - V_46 ;
T_1 V_47 , V_48 ;
unsigned char V_23 [ 7 ] ;
V_18 = F_21 ( sizeof( * V_18 ) , V_49 ) ;
if ( V_18 == NULL )
return - V_46 ;
if ( ( V_22 = F_22 ( V_2 , L_1 , V_5 , & V_29 ) ) < 0 ) {
F_19 ( V_18 ) ;
return V_22 ;
}
V_18 -> V_29 = V_29 ;
V_18 -> V_2 = V_2 ;
V_18 -> V_3 = V_3 ;
V_18 -> V_42 = V_42 ;
V_29 -> V_39 = V_18 ;
V_29 -> V_50 = F_18 ;
F_2 ( V_2 ) ;
V_18 -> V_26 [ V_51 ] = 0x3f ;
V_18 -> V_26 [ V_52 ] = V_3 ? 0 : V_53 ;
if ( ! V_18 -> V_3 ) {
V_18 -> V_32 = 9 ;
V_18 -> V_35 = 8 ;
V_48 = 3 + 4 ;
V_18 -> V_33 = 4 ;
V_47 = 3 + 4 ;
V_18 -> V_36 = 4 ;
} else {
V_18 -> V_32 = 5 ;
V_18 -> V_35 = 0 ;
V_48 = 7 + 4 ;
V_18 -> V_33 = 4 ;
V_47 = 3 ;
V_18 -> V_36 = 0 ;
}
V_18 -> V_19 = V_18 -> V_20 = 0x14 ;
V_18 -> V_26 [ V_34 ] = V_48 ;
V_18 -> V_26 [ V_37 ] = V_47 ;
V_23 [ 0 ] = V_27 ;
for ( V_45 = 0 ; V_45 < 6 ; V_45 ++ )
V_23 [ V_45 + 1 ] = V_18 -> V_26 [ V_45 ] ;
if ( ( V_22 = F_9 ( V_29 , V_23 , 7 ) ) < 0 )
goto V_54;
strcat ( V_41 -> V_55 , L_2 ) ;
if ( ( V_22 = F_23 ( V_41 , L_1 ) ) < 0 )
goto V_54;
for ( V_45 = 0 ; V_45 < F_24 ( V_56 ) ; V_45 ++ ) {
V_44 = & V_56 [ V_45 ] ;
if ( V_18 -> V_36 == 0 && ! strcmp ( V_44 -> V_57 , L_3 ) )
continue;
if ( ( V_22 = F_25 ( V_41 , F_26 ( V_44 , V_18 ) ) ) < 0 )
goto V_54;
}
F_4 ( V_2 ) ;
return 0 ;
V_54:
F_4 ( V_2 ) ;
F_27 ( V_29 ) ;
return V_22 ;
}
static int T_2 F_28 ( void )
{
return 0 ;
}
static void T_3 F_29 ( void )
{
}
