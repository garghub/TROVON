void T_1 F_1 ( int V_1 , T_2 V_2 ,
const char * V_3 , int V_4 ,
struct V_5 * V_6 )
{
strncpy ( V_7 . type , V_3 ,
sizeof( V_7 . type ) ) ;
V_7 . V_8 = V_4 ;
V_7 . V_9 = V_6 ;
F_2 ( V_1 , V_2 , & V_7 , 1 ) ;
}
void T_1 F_3 ( int V_10 , int V_11 , int V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_17 ;
int V_18 ;
if ( V_14 && V_14 -> V_19 ) {
V_18 = F_4 ( V_11 , V_20 , L_1 ) ;
if ( V_18 ) {
F_5 ( L_2 , V_18 ) ;
return;
}
F_6 ( V_11 , 0 ) ;
if ( V_12 )
F_7 ( V_11 , V_12 ) ;
}
V_21 . V_11 = V_11 ;
V_16 -> V_10 = V_10 ;
V_16 -> V_8 = F_8 ( V_11 ) ;
if ( V_14 )
V_16 -> V_9 = V_14 ;
F_9 ( & V_17 , 1 ) ;
}
void T_1 F_3 ( int V_10 , int V_11 , int V_12 ,
struct V_13 * V_14 )
{
}
void T_1 F_10 ( int V_22 , struct V_23 * V_24 ,
int V_25 )
{
T_3 V_26 = 0 ;
T_3 V_27 = V_28 + 1 ;
while ( V_26 < V_28 ) {
T_2 V_29 = 0 ;
V_29 = F_11 ( V_26 , V_30 ) ;
if ( ( V_29 & 0xC00 ) == 0x800 ) {
F_12 ( V_31 L_3 , V_26 ) ;
if ( V_27 > V_28 )
V_27 = V_26 ;
}
V_26 ++ ;
}
if ( V_27 > V_28 ) {
F_12 ( V_31 L_4
L_5 ) ;
return;
}
if ( V_27 < V_28 ) {
V_32 . V_26 = V_27 ;
V_32 . V_24 = V_24 ;
V_32 . V_25 = V_25 ;
V_32 . V_22 = V_22 ;
F_12 ( V_31 L_6 , V_27 ) ;
if ( F_13 ( & V_32 ) < 0 )
F_12 ( V_33 L_7 ) ;
}
}
void T_1 F_10 ( int V_22 , struct V_23 * V_24 ,
int V_25 )
{
}
