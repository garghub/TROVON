static int T_1 F_1 ( void )
{
V_1 . V_2 = F_2 ( F_3 ( V_3 ,
V_4 ) ) ;
if ( ! V_1 . V_2 )
return - V_5 ;
F_4 ( 1 , L_1 ,
F_3 ( V_3 , V_4 ) ) ;
V_6 . V_2 = F_2 ( F_5 () ) ;
if ( ! V_6 . V_2 ) {
F_6 ( V_1 . V_2 ) ;
return - V_5 ;
}
F_4 ( 1 , L_2 ,
F_5 () ) ;
return 0 ;
}
static void F_7 ( void )
{
F_6 ( V_1 . V_2 ) ;
F_6 ( V_6 . V_2 ) ;
}
static int F_8 ( unsigned char * V_7 ,
unsigned char * V_8 ,
T_2 * V_9 , T_2 * V_10 )
{
int V_11 ;
if ( * V_10 <= V_12 )
return - 1 ;
F_9 ( & V_13 ) ;
if ( V_14 != F_10 ( & V_1 , 3 ) ) {
F_11 ( L_3 ) ;
F_12 ( & V_13 ) ;
return - 1 ;
}
V_1 . V_15 = V_7 ;
V_1 . V_16 = 0 ;
V_1 . V_17 = V_8 ;
V_1 . V_18 = 0 ;
while ( V_1 . V_18 < * V_10 - V_12 && V_1 . V_16 < * V_9 ) {
V_1 . V_19 = * V_10 - ( V_1 . V_18 + V_12 ) ;
V_1 . V_20 = F_13 (unsigned long,
(*sourcelen-def_strm.total_in), def_strm.avail_out) ;
F_4 ( 1 , L_4 ,
V_1 . V_20 , V_1 . V_19 ) ;
V_11 = F_14 ( & V_1 , V_21 ) ;
F_4 ( 1 , L_5 ,
V_1 . V_20 , V_1 . V_19 ,
V_1 . V_16 , V_1 . V_18 ) ;
if ( V_11 != V_14 ) {
F_4 ( 1 , L_6 , V_11 ) ;
F_15 ( & V_1 ) ;
F_12 ( & V_13 ) ;
return - 1 ;
}
}
V_1 . V_19 += V_12 ;
V_1 . V_20 = 0 ;
V_11 = F_14 ( & V_1 , V_22 ) ;
F_15 ( & V_1 ) ;
if ( V_11 != V_23 ) {
F_4 ( 1 , L_7 , V_11 ) ;
V_11 = - 1 ;
goto V_24;
}
if ( V_1 . V_18 >= V_1 . V_16 ) {
F_4 ( 1 , L_8 ,
V_1 . V_16 , V_1 . V_18 ) ;
V_11 = - 1 ;
goto V_24;
}
F_4 ( 1 , L_9 ,
V_1 . V_16 , V_1 . V_18 ) ;
* V_10 = V_1 . V_18 ;
* V_9 = V_1 . V_16 ;
V_11 = 0 ;
V_24:
F_12 ( & V_13 ) ;
return V_11 ;
}
static int F_16 ( unsigned char * V_7 ,
unsigned char * V_8 ,
T_2 V_25 , T_2 V_26 )
{
int V_11 ;
int V_27 = V_3 ;
F_9 ( & V_28 ) ;
V_6 . V_15 = V_7 ;
V_6 . V_20 = V_25 ;
V_6 . V_16 = 0 ;
V_6 . V_17 = V_8 ;
V_6 . V_19 = V_26 ;
V_6 . V_18 = 0 ;
if ( V_25 > 2 && ! ( V_7 [ 1 ] & V_29 ) &&
( ( V_7 [ 0 ] & 0x0f ) == V_30 ) &&
! ( ( ( V_7 [ 0 ] << 8 ) + V_7 [ 1 ] ) % 31 ) ) {
F_4 ( 2 , L_10 ) ;
V_27 = - ( ( V_7 [ 0 ] >> 4 ) + 8 ) ;
V_6 . V_15 += 2 ;
V_6 . V_20 -= 2 ;
} else {
F_4 ( 1 , L_11 ) ;
}
if ( V_14 != F_17 ( & V_6 , V_27 ) ) {
F_11 ( L_12 ) ;
F_12 ( & V_28 ) ;
return 1 ;
}
while( ( V_11 = F_18 ( & V_6 , V_22 ) ) == V_14 )
;
if ( V_11 != V_23 ) {
F_19 ( L_13 , V_11 ) ;
}
F_20 ( & V_6 ) ;
F_12 ( & V_28 ) ;
return 0 ;
}
int T_1 F_21 ( void )
{
int V_11 ;
V_11 = F_1 () ;
if ( V_11 )
return V_11 ;
V_11 = F_22 ( & V_31 ) ;
if ( V_11 )
F_7 () ;
return V_11 ;
}
void F_23 ( void )
{
F_24 ( & V_31 ) ;
F_7 () ;
}
