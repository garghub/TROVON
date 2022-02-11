static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = V_2 -> V_8 & 0xff ;
int V_9 = ( V_2 -> V_8 >> 8 ) & 1 ;
V_4 -> V_10 . integer . V_10 [ 0 ] = ( V_6 -> V_11 >> V_7 ) & 1 ;
if ( V_9 )
V_4 -> V_10 . integer . V_10 [ 0 ] ^= 1 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
int V_7 = V_2 -> V_8 & 0xff ;
int V_9 = ( V_2 -> V_8 >> 8 ) & 1 ;
int V_13 ;
unsigned char V_14 , V_15 ;
V_15 = V_4 -> V_10 . integer . V_10 [ 0 ] & 1 ;
if ( V_9 )
V_15 ^= 1 ;
V_15 <<= V_7 ;
F_4 ( & V_6 -> V_16 , V_12 ) ;
V_14 = V_6 -> V_11 ;
V_15 = ( V_14 & ~ ( 1 << V_7 ) ) | V_15 ;
V_13 = V_15 != V_14 ;
F_5 ( V_6 -> V_11 = V_15 , F_6 ( V_6 , V_17 ) ) ;
F_5 ( V_6 -> V_18 . V_19 = 0 , F_6 ( V_6 , V_20 ) ) ;
F_7 ( & V_6 -> V_16 , V_12 ) ;
return V_13 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
V_22 -> type = V_23 ;
V_22 -> V_24 = 2 ;
V_22 -> V_10 . integer . V_25 = 0 ;
V_22 -> V_10 . integer . V_26 = 127 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
int V_27 = V_2 -> V_8 & 0xff ;
unsigned char V_28 , V_29 ;
F_4 ( & V_6 -> V_16 , V_12 ) ;
V_28 = V_6 -> V_18 . V_30 [ V_27 ] [ 0 ] ;
V_29 = V_6 -> V_18 . V_30 [ V_27 ] [ 1 ] ;
F_7 ( & V_6 -> V_16 , V_12 ) ;
V_4 -> V_10 . integer . V_10 [ 0 ] = V_28 & 127 ;
V_4 -> V_10 . integer . V_10 [ 1 ] = V_29 & 127 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
int V_27 = V_2 -> V_8 & 0xff ;
int V_13 ;
unsigned char V_31 , V_32 , V_33 , V_34 , V_35 ;
V_31 = V_4 -> V_10 . integer . V_10 [ 0 ] & 127 ;
V_32 = V_4 -> V_10 . integer . V_10 [ 1 ] & 127 ;
F_4 ( & V_6 -> V_16 , V_12 ) ;
V_33 = V_6 -> V_18 . V_30 [ V_27 ] [ 0 ] ;
V_34 = V_6 -> V_18 . V_30 [ V_27 ] [ 1 ] ;
V_13 = V_31 != V_33 || V_32 != V_34 ;
V_6 -> V_18 . V_30 [ V_27 ] [ 0 ] = V_31 ;
V_6 -> V_18 . V_30 [ V_27 ] [ 1 ] = V_32 ;
if ( V_6 -> V_36 && V_6 -> V_37 &&
( V_27 == V_38 || V_27 == V_39 ) ) {
V_35 = V_31 ;
V_31 = V_32 ;
V_32 = V_35 ;
}
V_27 <<= 3 ;
F_5 ( V_27 | 0 , F_6 ( V_6 , V_40 ) ) ;
F_5 ( 1 , F_6 ( V_6 , V_41 ) ) ;
F_5 ( V_27 | 2 , F_6 ( V_6 , V_40 ) ) ;
F_5 ( ( unsigned char ) V_31 , F_6 ( V_6 , V_41 ) ) ;
F_5 ( V_27 | 1 , F_6 ( V_6 , V_40 ) ) ;
F_5 ( 2 , F_6 ( V_6 , V_41 ) ) ;
F_5 ( V_27 | 3 , F_6 ( V_6 , V_40 ) ) ;
F_5 ( ( unsigned char ) V_32 , F_6 ( V_6 , V_41 ) ) ;
F_7 ( & V_6 -> V_16 , V_12 ) ;
return V_13 ;
}
int F_11 ( struct V_5 * V_6 )
{
struct V_42 * V_43 ;
unsigned int V_44 , V_26 ;
int V_45 ;
if ( F_12 ( ! V_6 ) )
return - V_46 ;
V_43 = V_6 -> V_43 ;
if ( F_12 ( ! V_43 ) )
return - V_46 ;
if ( V_6 -> V_36 )
F_13 ( V_43 , L_1 ) ;
if ( V_43 -> V_47 [ 0 ] == '\0' ) {
strcpy ( V_43 -> V_47 , V_6 -> V_36 ? L_2 : L_3 ) ;
} else {
if ( V_6 -> V_36 )
strcat ( V_43 -> V_47 , L_4 ) ;
strcat ( V_43 -> V_47 , L_5 ) ;
}
if ( ! V_6 -> V_36 ) {
V_26 = V_6 -> V_48 ? 1 : F_14 ( V_49 ) ;
for ( V_44 = 0 ; V_44 < V_26 ; V_44 ++ ) {
if ( ( V_45 = F_15 ( V_43 , F_16 ( & V_49 [ V_44 ] , V_6 ) ) ) < 0 )
return V_45 ;
}
} else {
for ( V_44 = 0 ; V_44 < F_14 ( V_50 ) ; V_44 ++ ) {
if ( ( V_45 = F_15 ( V_43 , F_16 ( & V_50 [ V_44 ] , V_6 ) ) ) < 0 )
return V_45 ;
}
}
return 0 ;
}
