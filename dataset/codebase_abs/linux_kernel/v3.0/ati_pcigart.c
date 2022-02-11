static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = F_2 ( V_2 , V_4 -> V_6 ,
V_7 ) ;
if ( V_4 -> V_5 == NULL )
return - V_8 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_4 ( V_2 , V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
}
int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned long V_12 ;
int V_13 ;
int V_14 ;
if ( ! V_10 ) {
F_6 ( L_1 ) ;
return 0 ;
}
if ( V_4 -> V_15 ) {
V_14 = ( V_4 -> V_6 / sizeof( V_16 ) ) ;
V_12 = ( V_10 -> V_12 <= V_14 )
? V_10 -> V_12 : V_14 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
if ( ! V_10 -> V_17 [ V_13 ] )
break;
F_7 ( V_2 -> V_18 , V_10 -> V_17 [ V_13 ] ,
V_7 , V_19 ) ;
}
if ( V_4 -> V_20 == V_21 )
V_4 -> V_15 = 0 ;
}
if ( V_4 -> V_20 == V_21 &&
V_4 -> V_5 ) {
F_3 ( V_2 , V_4 ) ;
}
return 1 ;
}
int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_22 * V_23 = & V_4 -> V_24 ;
struct V_9 * V_10 = V_2 -> V_11 ;
void * V_25 = NULL ;
unsigned long V_12 ;
V_16 * V_26 = NULL , V_27 , V_28 ;
T_1 V_29 = 0 ;
int V_13 , V_30 , V_31 = 0 ;
int V_32 , V_33 ;
if ( ! V_10 ) {
F_6 ( L_1 ) ;
goto V_34;
}
if ( V_4 -> V_20 == V_21 ) {
F_9 ( L_2 ) ;
if ( F_10 ( V_2 -> V_18 , V_4 -> V_35 ) ) {
F_6 ( L_3 ,
( unsigned long long ) V_4 -> V_35 ) ;
V_31 = 1 ;
goto V_34;
}
V_31 = F_1 ( V_2 , V_4 ) ;
if ( V_31 ) {
F_6 ( L_4 ) ;
goto V_34;
}
V_26 = V_4 -> V_5 -> V_36 ;
V_25 = V_4 -> V_5 -> V_36 ;
V_29 = V_4 -> V_5 -> V_17 ;
} else {
V_25 = V_4 -> V_37 ;
V_29 = V_4 -> V_15 ;
F_9 ( L_5 ,
( unsigned long long ) V_29 ,
( unsigned long ) V_25 ) ;
}
V_32 = ( V_4 -> V_6 / sizeof( V_16 ) ) ;
V_33 = V_32 / ( V_7 / V_38 ) ;
V_12 = ( V_10 -> V_12 <= V_33 )
? V_10 -> V_12 : V_33 ;
if ( V_4 -> V_20 == V_21 ) {
memset ( V_26 , 0 , V_32 * sizeof( V_16 ) ) ;
} else {
F_11 ( ( void V_39 * ) V_23 -> V_40 , 0 , V_32 * sizeof( V_16 ) ) ;
}
V_28 = 0 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_10 -> V_17 [ V_13 ] = F_12 ( V_2 -> V_18 , V_10 -> V_41 [ V_13 ] ,
0 , V_7 , V_19 ) ;
if ( F_13 ( V_2 -> V_18 , V_10 -> V_17 [ V_13 ] ) ) {
F_6 ( L_6 ) ;
F_5 ( V_2 , V_4 ) ;
V_25 = NULL ;
V_29 = 0 ;
goto V_34;
}
V_27 = ( V_16 ) V_10 -> V_17 [ V_13 ] ;
for ( V_30 = 0 ; V_30 < ( V_7 / V_38 ) ; V_30 ++ ) {
V_16 V_42 ;
switch( V_4 -> V_43 ) {
case V_44 :
V_42 = V_27 | 0xc ;
break;
case V_45 :
V_42 = ( V_27 >> 8 ) | 0xc ;
break;
default:
case V_46 :
V_42 = V_27 ;
break;
}
if ( V_4 -> V_20 ==
V_21 )
V_26 [ V_28 ] = F_14 ( V_42 ) ;
else
F_15 ( V_23 , V_28 * sizeof( V_16 ) , V_42 ) ;
V_28 ++ ;
V_27 += V_38 ;
}
}
V_31 = 1 ;
#if F_16 ( V_47 ) || F_16 ( V_48 )
F_17 () ;
#else
F_18 () ;
#endif
V_34:
V_4 -> V_37 = V_25 ;
V_4 -> V_15 = V_29 ;
return V_31 ;
}
