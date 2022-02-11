static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_1 V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( F_2 ( V_2 , V_7 , & V_4 ) )
return - V_8 ;
if ( ( V_4 & 0x3000 ) == 0x3000 ) {
if ( V_3 )
* V_3 = V_4 ;
return V_4 & 0xFF ;
}
}
return - V_9 ;
}
static int F_3 ( struct V_10 * V_11 , T_1 V_12 , T_2 V_13 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_14 = 0 ;
int V_15 ;
int V_16 = 0 ;
int V_17 = 0 ;
int V_18 = 0 ;
T_1 V_3 ;
T_1 V_19 = 0 ;
V_16 = F_1 ( V_2 , NULL ) ;
if ( V_16 )
return V_16 ;
if ( F_4 ( V_2 , V_20 ,
V_21 | V_22 ) )
return - V_8 ;
V_17 = 1 ;
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ ) {
if ( F_5 ( V_2 , V_24 , V_12 ) )
break;
if ( F_4 ( V_2 , V_25 , V_13 ) )
break;
V_16 = F_1 ( V_2 , & V_3 ) ;
if ( V_16 < 0 )
return 0 ;
if ( ( V_3 & V_26 )
&& V_11 -> V_2 -> V_27 == 0 )
break;
if ( V_3 & V_28 ) {
F_6 ( 10 ) ;
continue;
}
V_18 = 1 ;
break;
}
F_6 ( 10 ) ;
while ( V_17 ) {
if ( F_4 ( V_2 , V_20 ,
V_21 ) )
V_18 = 0 ;
do {
F_5 ( V_2 ,
V_24 ,
V_12 ) ;
do {
F_2 ( V_2 ,
V_25 , & V_19 ) ;
} while ( ( V_19 & 0x00010000 ) == 0 );
} while ( V_19 & 0x00040000 );
if ( ( V_19 & 0xFF00 ) != 0xC000 || V_14 == 10000 )
break;
V_14 ++ ;
}
return V_18 ? 0 : - V_8 ;
}
static int F_7 ( struct V_10 * V_11 , T_1 V_12 , T_2 * V_29 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_16 ;
T_1 V_3 ;
V_16 = F_1 ( V_2 , NULL ) ;
if ( V_16 )
return V_16 ;
if ( F_4 ( V_2 , V_20 ,
V_21 ) )
return - V_8 ;
if ( F_5 ( V_2 , V_24 , V_12 ) )
return - V_8 ;
V_16 = F_1 ( V_2 , & V_3 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_29 = V_16 ;
return ( V_3 & V_28 ) ? - V_8 : 0 ;
}
int F_8 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_2 V_30 ;
F_9 ( V_2 , V_31 ,
& V_30 ) ;
if ( F_9 ( V_2 , V_31 , & V_30 ) ) {
F_10 ( & V_2 -> V_32 ,
L_1 ) ;
return - V_8 ;
}
if ( V_30 & 0x4C ) {
int V_33 = 0 ;
if ( V_2 -> V_27 == 0x01 ) {
int V_5 ;
static const T_2 V_34 [ 4 ] = { 0xFE , 0x13 , 0x10 , 0xFF } ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ )
if ( F_3 ( V_11 , V_5 , V_34 [ V_5 ] ) < 0 )
V_33 = 1 ;
}
if ( V_2 -> V_27 != 0x01 || V_33 ) {
F_10 ( & V_2 -> V_32 ,
L_2 , V_30 ) ;
V_11 -> V_35 = 0 ;
return - V_8 ;
}
}
V_11 -> V_35 = 1 ;
F_7 ( V_11 , 0x70 , & V_11 -> V_36 [ 0 ] ) ;
F_7 ( V_11 , 0x71 , & V_11 -> V_36 [ 1 ] ) ;
if ( V_11 -> V_36 [ 0 ] != 0xcd )
V_11 -> V_36 [ 1 ] = 0x00 ;
return 0 ;
}
