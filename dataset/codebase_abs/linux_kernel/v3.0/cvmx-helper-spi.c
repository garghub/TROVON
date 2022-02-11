int F_1 ( int V_1 )
{
int V_2 = 0 ;
if ( ( F_2 () -> V_3 != V_4 ) &&
F_3 ( V_1 ) ) {
V_2 = 10 ;
} else {
union V_5 V_6 ;
V_2 = 16 ;
V_6 . V_7 = F_4 ( V_8 ) ;
V_6 . V_9 . V_6 |= 0xffff << ( V_1 * 16 ) ;
F_5 ( V_8 , V_6 . V_7 ) ;
}
F_6 ( V_1 , V_2 ) ;
return V_2 ;
}
int F_7 ( int V_1 )
{
int V_2 = F_8 ( V_1 ) ;
int V_10 ;
for ( V_10 = V_1 * 16 ; V_10 < V_1 * 16 + V_2 ;
V_10 ++ ) {
union V_11 V_12 ;
V_12 . V_7 = F_4 ( F_9 ( V_10 ) ) ;
V_12 . V_9 . V_13 = 1 ;
F_5 ( F_9 ( V_10 ) , V_12 . V_7 ) ;
}
if ( F_2 () -> V_3 != V_4 ) {
F_10 ( V_1 , V_14 ,
V_15 , V_2 ) ;
if ( F_3 ( V_1 ) )
F_11 ( V_1 ) ;
}
F_12 ( V_1 ) ;
F_13 ( V_1 ) ;
F_14 ( V_1 ) ;
return 0 ;
}
T_1 F_15 ( int V_10 )
{
T_1 V_16 ;
int V_1 = F_16 ( V_10 ) ;
int V_17 = F_17 ( V_10 ) ;
V_16 . V_7 = 0 ;
if ( F_2 () -> V_3 == V_4 ) {
V_16 . V_9 . V_18 = 1 ;
V_16 . V_9 . V_19 = 1 ;
V_16 . V_9 . V_20 = 10000 ;
} else if ( F_3 ( V_1 ) ) {
union V_21 V_22 =
F_18 ( V_1 , V_17 ) ;
V_16 . V_9 . V_18 = V_22 . V_9 . V_23 ;
V_16 . V_9 . V_19 = V_22 . V_9 . V_24 ;
switch ( V_22 . V_9 . V_20 ) {
case 0 :
V_16 . V_9 . V_20 = 10 ;
break;
case 1 :
V_16 . V_9 . V_20 = 100 ;
break;
case 2 :
V_16 . V_9 . V_20 = 1000 ;
break;
case 3 :
V_16 . V_9 . V_20 = 0 ;
V_16 . V_9 . V_18 = 0 ;
break;
}
} else {
V_16 . V_9 . V_18 = 1 ;
V_16 . V_9 . V_19 = 1 ;
V_16 . V_9 . V_20 = 10000 ;
}
return V_16 ;
}
int F_19 ( int V_10 , T_1 V_25 )
{
return 0 ;
}
