unsigned long F_1 ( T_1 V_1 , T_2 V_2 ,
unsigned long V_3 , T_3 V_4 )
{
T_4 V_5 = F_2 ( V_1 ) ;
unsigned V_6 ;
if ( ( V_3 % V_7 ) + V_4 <= V_7 )
return F_3 ( V_5 , V_2 ) + ( V_3 % V_7 ) ;
if ( ( V_3 % V_8 ) + V_4 > V_8 ) {
F_4 ( V_9 L_1
L_2 ,
V_5 , V_2 , V_3 , V_4 ) ;
return 0 ;
}
V_3 &= ~ ( V_8 - 1 ) ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
if ( F_5 ( V_6 , F_6 ( V_1 ) -> V_11 ) )
continue;
F_7 ( V_5 , V_6 , V_12 , V_2 , V_3 ) ;
( void ) F_8 ( F_9 ( V_5 , V_6 ) ) ;
return F_10 ( V_5 , V_2 ) + ( V_3 % V_8 ) ;
}
F_4 ( V_9 L_3
L_4 ,
V_5 , V_2 , V_3 ) ;
return 0 ;
}
static void F_11 ( T_4 V_5 , int V_13 , int V_14 )
{
T_5 V_15 ;
int V_16 ;
V_16 = F_12 ( V_13 ) ;
V_15 . V_17 = F_13 ( V_5 , V_16 ) ;
V_15 . V_18 = 1 ;
V_15 . V_19 = 0 ;
V_15 . V_20 = 0 ;
V_15 . V_21 = V_22 ? 1 : 0 ;
V_15 . V_23 = V_14 ;
F_14 ( V_5 , V_16 , V_15 . V_17 ) ;
}
static void F_15 ( T_4 V_5 )
{
T_6 V_24 ;
T_7 V_25 ;
unsigned V_6 ;
V_24 = F_13 ( V_5 , V_26 ) ;
F_14 ( V_5 , V_26 , 0 ) ;
V_25 . V_27 = F_13 ( V_5 , V_28 ) ;
if ( V_25 . V_29 ) {
F_11 ( V_5 , 0 , 3 ) ;
} else {
F_11 ( V_5 , 0 , 1 ) ;
}
for ( V_6 = V_30 ; V_6 <= V_31 ; V_6 ++ )
F_11 ( V_5 , V_6 , 3 ) ;
F_14 ( V_5 , V_26 , V_24 ) ;
}
void F_16 ( T_1 V_1 )
{
T_4 V_5 = F_2 ( V_1 ) ;
unsigned V_6 ;
F_17 ( F_6 ( V_1 ) -> V_11 , V_10 ) ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ )
F_18 ( V_5 , V_6 ) ;
F_15 ( V_5 ) ;
}
