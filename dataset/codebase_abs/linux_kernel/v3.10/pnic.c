void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_6 ;
T_2 V_7 = F_3 ( V_5 + 0xB8 ) ;
T_2 V_8 = V_4 -> V_9 & ~ 0x40C40200 ;
if ( V_7 & 0x78000000 ) {
if ( V_7 & 0x20000000 ) V_2 -> V_10 = 5 ;
else if ( V_7 & 0x40000000 ) V_2 -> V_10 = 3 ;
else if ( V_7 & 0x10000000 ) V_2 -> V_10 = 4 ;
else if ( V_7 & 0x08000000 ) V_2 -> V_10 = 0 ;
V_4 -> V_11 = 1 ;
V_8 = ( V_2 -> V_10 & 1 ) ? 0x01860000 : 0x00420000 ;
F_4 ( 0x32 | ( V_2 -> V_10 & 1 ) , V_5 + V_12 ) ;
if ( V_2 -> V_10 & 1 )
F_4 ( 0x1F868 , V_5 + 0xB8 ) ;
if ( V_7 & 0x30000000 ) {
V_4 -> V_13 = 1 ;
V_8 |= 0x00000200 ;
}
if ( V_14 > 1 )
F_5 ( V_2 , L_1 ,
V_7 , V_15 [ V_2 -> V_10 ] ) ;
if ( V_4 -> V_9 != V_8 ) {
V_4 -> V_9 = V_8 ;
F_6 ( V_4 ) ;
V_2 -> V_16 = V_17 ;
}
}
}
void F_7 ( struct V_1 * V_2 , int V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_6 ;
int V_7 = F_3 ( V_5 + 0xB8 ) ;
if ( V_14 > 1 )
F_5 ( V_2 , L_2 ,
V_7 , V_18 ) ;
if ( F_3 ( V_5 + V_19 ) & V_20 ) {
F_4 ( ( F_3 ( V_5 + V_21 ) & ~ V_20 ) | V_22 , V_5 + V_21 ) ;
if ( V_23 [ V_2 -> V_10 ] & V_24 )
return;
if ( ! V_4 -> V_11 || F_8 ( V_17 , F_9 ( V_2 ) + 1 * V_25 ) ) {
V_4 -> V_9 = 0x00420000 | ( V_4 -> V_9 & 0x0000fdff ) ;
F_4 ( V_4 -> V_9 , V_5 + V_26 ) ;
F_4 ( 0x30 , V_5 + V_12 ) ;
F_4 ( 0x0201F078 , V_5 + 0xB8 ) ;
V_2 -> V_16 = V_17 ;
}
} else if ( F_3 ( V_5 + V_19 ) & V_22 ) {
if ( V_23 [ V_2 -> V_10 ] & V_24 ) {
F_10 ( & V_4 -> V_27 ) ;
F_11 ( V_2 ) ;
F_12 ( & V_4 -> V_27 ) ;
} else {
F_1 ( V_2 ) ;
}
F_4 ( ( F_3 ( V_5 + V_21 ) & ~ V_22 ) | V_20 , V_5 + V_21 ) ;
}
}
void F_13 ( unsigned long V_28 )
{
struct V_1 * V_2 = (struct V_1 * ) V_28 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_6 ;
int V_29 = 60 * V_25 ;
if( ! F_3 ( V_5 + V_21 ) ) {
goto V_30;
}
if ( V_23 [ V_2 -> V_10 ] & V_24 ) {
F_14 ( & V_4 -> V_27 ) ;
if ( F_11 ( V_2 ) > 0 )
V_29 = 3 * V_25 ;
F_15 ( & V_4 -> V_27 ) ;
} else {
int V_31 = F_3 ( V_5 + V_12 ) ;
int V_8 = V_4 -> V_9 & ~ 0x40C40200 ;
int V_7 = F_3 ( V_5 + 0xB8 ) ;
int V_18 = F_3 ( V_5 + V_19 ) ;
if ( V_14 > 1 )
F_5 ( V_2 , L_3 ,
V_7 , V_15 [ V_2 -> V_10 ] , V_18 ) ;
if ( V_7 & 0x04000000 ) {
F_4 ( 0x0201F078 , V_5 + 0xB8 ) ;
V_29 = 1 * V_25 ;
V_4 -> V_11 = 0 ;
} else if ( V_7 & 0x78000000 ) {
F_1 ( V_2 ) ;
V_29 = 60 * V_25 ;
} else if ( V_18 & V_20 ) {
if ( V_14 > 1 )
F_5 ( V_2 , L_4 ,
V_15 [ V_2 -> V_10 ] ,
V_31 ,
F_3 ( V_5 + V_19 ) ,
F_3 ( V_5 + 0xB8 ) ) ;
V_29 = 3 * V_25 ;
if ( V_4 -> V_32 ) {
} else if ( V_4 -> V_11 && ( V_2 -> V_10 & 1 ) ) {
V_29 = 1 * V_25 ;
} else if ( V_2 -> V_10 == 0 ) {
V_2 -> V_10 = 3 ;
F_4 ( 0x33 , V_5 + V_12 ) ;
V_8 = 0x01860000 ;
F_4 ( 0x1F868 , V_5 + 0xB8 ) ;
} else {
V_2 -> V_10 = 0 ;
F_4 ( 0x32 , V_5 + V_12 ) ;
V_8 = 0x00420000 ;
F_4 ( 0x1F078 , V_5 + 0xB8 ) ;
}
if ( V_4 -> V_9 != V_8 ) {
V_4 -> V_9 = V_8 ;
F_6 ( V_4 ) ;
V_2 -> V_16 = V_17 ;
if ( V_14 > 1 )
F_16 ( & V_2 -> V_2 ,
L_5 ,
V_15 [ V_2 -> V_10 ] ,
V_4 -> V_13 ? L_6 : L_7 ,
V_8 ) ;
}
}
}
V_30:
F_17 ( & V_4 -> V_33 , F_18 ( V_29 ) ) ;
if( ! F_3 ( V_5 + V_21 ) ) {
if ( V_14 > 1 )
F_16 ( & V_2 -> V_2 , L_8 ) ;
F_19 ( V_2 -> V_34 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 -> V_34 ) ;
F_4 ( V_35 [ V_4 -> V_36 ] . V_37 , V_5 + V_21 ) ;
}
}
