int T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 ,
struct V_4 * V_5 )
{
int V_6 = V_5 -> V_7 * V_5 -> V_8 ;
T_3 V_9 [ 3 ] ;
T_3 V_10 [ 3 ] ;
V_10 [ 0 ] = F_2 ( 'Q' , V_2 , V_5 ) ;
V_10 [ 1 ] = F_2 ( 'R' , V_2 , V_5 ) ;
V_10 [ 2 ] = F_2 ( 'Y' , V_2 , V_5 ) ;
V_9 [ 0 ] = F_3 ( V_2 , V_3 + V_6 * 0x10 ) ;
V_9 [ 1 ] = F_3 ( V_2 , V_3 + V_6 * 0x11 ) ;
V_9 [ 2 ] = F_3 ( V_2 , V_3 + V_6 * 0x12 ) ;
if ( ! F_4 ( V_2 , V_10 [ 0 ] , V_9 [ 0 ] ) )
return 0 ;
if ( ! F_4 ( V_2 , V_10 [ 1 ] , V_9 [ 1 ] ) )
return 0 ;
if ( ! F_4 ( V_2 , V_10 [ 2 ] , V_9 [ 2 ] ) )
return 0 ;
return 1 ;
}
int T_1 F_5 ( T_4 V_3 , struct V_1 * V_2 ,
struct V_4 * V_5 )
{
F_6 ( 0xF0 , 0 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
F_6 ( 0x98 , 0x55 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
if ( F_1 ( V_2 , V_3 , V_5 ) )
return 1 ;
F_6 ( 0xF0 , 0 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
F_6 ( 0xFF , 0 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
F_6 ( 0x98 , 0x55 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
if ( F_1 ( V_2 , V_3 , V_5 ) )
return 1 ;
F_6 ( 0xF0 , 0 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
F_6 ( 0x98 , 0x555 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
if ( F_1 ( V_2 , V_3 , V_5 ) )
return 1 ;
F_6 ( 0xF0 , 0 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
F_6 ( 0xAA , 0x5555 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
F_6 ( 0x55 , 0x2AAA , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
F_6 ( 0x98 , 0x5555 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
if ( F_1 ( V_2 , V_3 , V_5 ) )
return 1 ;
F_6 ( 0xF0 , 0 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
F_6 ( 0xAA , 0x555 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
F_6 ( 0x55 , 0x2AA , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
F_6 ( 0x98 , 0x555 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
if ( F_1 ( V_2 , V_3 , V_5 ) )
return 1 ;
return 0 ;
}
void T_1 F_7 ( T_4 V_3 , struct V_1 * V_2 ,
struct V_4 * V_5 )
{
F_6 ( 0xF0 , 0 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
F_6 ( 0xFF , 0 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
if ( ( V_5 -> V_11 == V_12 ) && ( V_5 -> V_13 == 0x227E || V_5 -> V_13 == 0x7E ) )
F_6 ( 0xF0 , 0 , V_3 , V_2 , V_5 , V_5 -> V_8 , NULL ) ;
}
struct V_14 *
T_1 F_8 ( struct V_1 * V_2 , T_5 V_15 , T_5 V_16 , const char * V_17 )
{
struct V_4 * V_5 = V_2 -> V_18 ;
T_2 V_3 = 0 ;
int V_19 = V_5 -> V_7 * V_5 -> V_8 ;
int V_20 ;
struct V_14 * V_21 = NULL ;
if ( ! V_15 )
goto V_22;
F_9 ( V_23 L_1 , V_17 , V_15 ) ;
V_21 = F_10 ( V_16 , V_24 ) ;
if ( ! V_21 ) {
F_9 ( V_25 L_2 ) ;
goto V_22;
}
#ifdef F_11
F_12 () ;
#endif
F_5 ( V_3 , V_2 , V_5 ) ;
for ( V_20 = 0 ; V_20 < V_16 ; V_20 ++ ) {
( ( unsigned char * ) V_21 ) [ V_20 ] =
F_13 ( V_2 , V_3 + ( ( V_15 + V_20 ) * V_19 ) ) ;
}
F_7 ( V_3 , V_2 , V_5 ) ;
#ifdef F_11
( void ) F_3 ( V_2 , V_3 ) ;
F_14 () ;
F_15 () ;
#endif
V_22: return V_21 ;
}
void F_16 ( struct V_26 * V_27 , struct F_16 * V_28 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_4 * V_5 = V_2 -> V_18 ;
struct F_16 * V_30 ;
for ( V_30 = V_28 ; V_30 -> V_31 ; V_30 ++ ) {
if ( ( ( V_30 -> V_11 == V_32 ) || ( V_30 -> V_11 == V_5 -> V_11 ) ) &&
( ( V_30 -> V_13 == V_33 ) || ( V_30 -> V_13 == V_5 -> V_13 ) ) ) {
V_30 -> V_31 ( V_27 ) ;
}
}
}
int F_17 ( struct V_26 * V_27 , T_6 V_34 ,
T_7 V_35 , T_8 V_36 , void * V_37 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_4 * V_5 = V_2 -> V_18 ;
unsigned long V_15 ;
int V_38 , V_39 = 0 ;
int V_20 , V_40 ;
struct V_41 * V_42 = V_27 -> V_43 ;
V_20 = 0 ;
while ( V_20 < V_27 -> V_44 && V_35 >= V_42 [ V_20 ] . V_45 )
V_20 ++ ;
V_20 -- ;
if ( V_35 & ( V_42 [ V_20 ] . V_46 - 1 ) )
return - V_47 ;
V_40 = V_20 ;
while ( V_20 < V_27 -> V_44 && ( V_35 + V_36 ) >= V_42 [ V_20 ] . V_45 )
V_20 ++ ;
V_20 -- ;
if ( ( V_35 + V_36 ) & ( V_42 [ V_20 ] . V_46 - 1 ) )
return - V_47 ;
V_38 = V_35 >> V_5 -> V_48 ;
V_15 = V_35 - ( V_38 << V_5 -> V_48 ) ;
V_20 = V_40 ;
while( V_36 ) {
int V_16 = V_42 [ V_20 ] . V_46 ;
V_39 = (* V_34)( V_2 , & V_5 -> V_49 [ V_38 ] , V_15 , V_16 , V_37 ) ;
if ( V_39 )
return V_39 ;
V_15 += V_16 ;
V_35 += V_16 ;
V_36 -= V_16 ;
if ( V_35 == V_42 [ V_20 ] . V_45 + V_16 * V_42 [ V_20 ] . V_50 )
V_20 ++ ;
if ( V_15 >> V_5 -> V_48 ) {
V_15 = 0 ;
V_38 ++ ;
if ( V_38 >= V_5 -> V_51 )
break;
}
}
return 0 ;
}
