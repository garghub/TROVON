static int F_1 ( int V_1 , struct V_2 * V_3 )
{
unsigned char V_4 = V_5 ;
if ( ! V_1 )
V_4 |= V_6 | V_7 ;
V_8 [ 0 ] = V_4 ;
return 0 ;
}
static int F_2 ( T_1 V_9 , T_1 V_10 , T_1 V_11 , T_1 V_12 ,
T_1 V_13 , struct V_2 * V_3 )
{
if ( V_9 < 16 ) {
V_10 >>= 8 ;
V_11 >>= 8 ;
V_12 >>= 8 ;
( ( V_14 * ) ( V_3 -> V_15 ) ) [ V_9 ] = ( V_10 << 16 ) |
( V_11 << 8 ) | V_12 ;
}
return 0 ;
}
static int F_3 ( struct V_16 * V_17 , const struct V_18 * V_19 )
{
struct V_2 * V_3 ;
unsigned long * V_20 ;
int V_21 ;
int V_22 , V_23 ;
V_21 = V_17 -> V_19 == V_24 ;
if ( ! F_4 ( V_17 , L_1 ) )
return - V_25 ;
V_3 = F_5 ( 16 * sizeof( V_14 ) , & V_17 -> V_26 ) ;
if ( ! V_3 ) {
F_6 ( V_17 ) ;
return - V_27 ;
}
if ( F_7 ( & V_3 -> V_28 , 256 , 0 ) < 0 ) {
F_8 ( V_3 ) ;
F_6 ( V_17 ) ;
return - V_27 ;
}
V_29 . V_30 = F_9 ( V_17 ) ;
V_3 -> V_31 = F_10 ( V_29 . V_30 , V_32 ) ;
V_29 . V_33 = V_29 . V_30 + V_34 ;
V_8 = ( unsigned char * ) ( V_3 -> V_31 + V_34 ) ;
strcpy ( V_29 . V_19 , V_21 ? L_2 : L_3 ) ;
V_20 = ( unsigned long * ) V_29 . V_30 ;
for ( V_23 = 0 ; V_23 < 576 ; V_23 ++ ) {
for ( V_22 = 0 ; V_22 < 96 ; V_22 ++ ) * V_20 ++ = 0xffffff ;
for ( V_22 = 0 ; V_22 < 96 ; V_22 ++ ) * V_20 ++ = 0xffff00 ;
for ( V_22 = 0 ; V_22 < 96 ; V_22 ++ ) * V_20 ++ = 0x00ffff ;
for ( V_22 = 0 ; V_22 < 96 ; V_22 ++ ) * V_20 ++ = 0x00ff00 ;
for ( V_22 = 0 ; V_22 < 96 ; V_22 ++ ) * V_20 ++ = 0xff00ff ;
for ( V_22 = 0 ; V_22 < 96 ; V_22 ++ ) * V_20 ++ = 0xff0000 ;
for ( V_22 = 0 ; V_22 < 96 ; V_22 ++ ) * V_20 ++ = 0x0000ff ;
for ( V_22 = 0 ; V_22 < 96 ; V_22 ++ ) * V_20 ++ = 0x000000 ;
}
F_1 ( 0 , V_3 ) ;
if ( V_35 == - 1 )
V_35 = V_36 ;
V_3 -> V_37 = & V_38 ;
V_3 -> V_39 = V_40 [ V_35 ] ;
V_3 -> V_15 = V_3 -> V_41 ;
V_3 -> V_41 = NULL ;
V_3 -> V_42 = V_29 ;
V_3 -> V_43 = V_44 ;
if ( F_11 ( V_3 ) < 0 ) {
F_12 ( & V_3 -> V_28 ) ;
F_13 ( V_3 -> V_31 ) ;
F_8 ( V_3 ) ;
F_6 ( V_17 ) ;
return - V_45 ;
}
F_14 ( L_4 , V_3 -> V_46 , V_29 . V_19 ) ;
return 0 ;
}
int T_2 F_15 ( char * V_47 )
{
char * V_48 ;
if ( ! V_47 || ! * V_47 )
return 0 ;
while ( ( V_48 = F_16 ( & V_47 , L_5 ) ) != NULL ) {
if ( ! strncmp ( V_48 , L_6 , 3 ) )
V_35 = V_36 ;
else if ( ! strncmp ( V_48 , L_7 , 4 ) )
V_35 = V_49 ;
}
return 0 ;
}
int T_2 F_17 ( void )
{
char * V_50 = NULL ;
if ( F_18 ( L_1 , & V_50 ) )
return - V_51 ;
F_15 ( V_50 ) ;
return F_19 ( & V_52 ) ;
}
