static int T_1 F_1 ( void )
{
V_1 . V_2 = F_2 ( F_3 ( V_3 ,
V_4 ) ) ;
if ( ! V_1 . V_2 ) {
F_4 ( V_5 L_1 , F_3 ( V_3 , V_4 ) ) ;
return - V_6 ;
}
F_5 ( F_4 ( V_7 L_2 , F_3 ( V_3 , V_4 ) ) ) ;
V_8 . V_2 = F_2 ( F_6 () ) ;
if ( ! V_8 . V_2 ) {
F_4 ( V_5 L_3 , F_6 () ) ;
F_7 ( V_1 . V_2 ) ;
return - V_6 ;
}
F_5 ( F_4 ( V_7 L_4 , F_6 () ) ) ;
return 0 ;
}
static void F_8 ( void )
{
F_7 ( V_1 . V_2 ) ;
F_7 ( V_8 . V_2 ) ;
}
static int F_9 ( unsigned char * V_9 ,
unsigned char * V_10 ,
T_2 * V_11 , T_2 * V_12 )
{
int V_13 ;
if ( * V_12 <= V_14 )
return - 1 ;
F_10 ( & V_15 ) ;
if ( V_16 != F_11 ( & V_1 , 3 ) ) {
F_4 ( V_5 L_5 ) ;
F_12 ( & V_15 ) ;
return - 1 ;
}
V_1 . V_17 = V_9 ;
V_1 . V_18 = 0 ;
V_1 . V_19 = V_10 ;
V_1 . V_20 = 0 ;
while ( V_1 . V_20 < * V_12 - V_14 && V_1 . V_18 < * V_11 ) {
V_1 . V_21 = * V_12 - ( V_1 . V_20 + V_14 ) ;
V_1 . V_22 = F_13 ( ( unsigned ) ( * V_11 - V_1 . V_18 ) , V_1 . V_21 ) ;
F_5 ( F_4 ( V_7 L_6 ,
V_1 . V_22 , V_1 . V_21 ) ) ;
V_13 = F_14 ( & V_1 , V_23 ) ;
F_5 ( F_4 ( V_7 L_7 ,
V_1 . V_22 , V_1 . V_21 , V_1 . V_18 , V_1 . V_20 ) ) ;
if ( V_13 != V_16 ) {
F_5 ( F_4 ( V_7 L_8 , V_13 ) ) ;
F_15 ( & V_1 ) ;
F_12 ( & V_15 ) ;
return - 1 ;
}
}
V_1 . V_21 += V_14 ;
V_1 . V_22 = 0 ;
V_13 = F_14 ( & V_1 , V_24 ) ;
F_15 ( & V_1 ) ;
if ( V_13 != V_25 ) {
F_5 ( F_4 ( V_7 L_9 , V_13 ) ) ;
V_13 = - 1 ;
goto V_26;
}
if ( V_1 . V_20 >= V_1 . V_18 ) {
F_5 ( F_4 ( V_7 L_10 ,
V_1 . V_18 , V_1 . V_20 ) ) ;
V_13 = - 1 ;
goto V_26;
}
F_5 ( F_4 ( V_7 L_11 ,
V_1 . V_18 , V_1 . V_20 ) ) ;
* V_12 = V_1 . V_20 ;
* V_11 = V_1 . V_18 ;
V_13 = 0 ;
V_26:
F_12 ( & V_15 ) ;
return V_13 ;
}
static int F_16 ( unsigned char * V_9 ,
unsigned char * V_10 ,
T_2 V_27 , T_2 V_28 )
{
int V_13 ;
int V_29 = V_3 ;
F_10 ( & V_30 ) ;
V_8 . V_17 = V_9 ;
V_8 . V_22 = V_27 ;
V_8 . V_18 = 0 ;
V_8 . V_19 = V_10 ;
V_8 . V_21 = V_28 ;
V_8 . V_20 = 0 ;
if ( V_27 > 2 && ! ( V_9 [ 1 ] & V_31 ) &&
( ( V_9 [ 0 ] & 0x0f ) == V_32 ) &&
! ( ( ( V_9 [ 0 ] << 8 ) + V_9 [ 1 ] ) % 31 ) ) {
F_17 ( F_4 ( V_7 L_12 ) ) ;
V_29 = - ( ( V_9 [ 0 ] >> 4 ) + 8 ) ;
V_8 . V_17 += 2 ;
V_8 . V_22 -= 2 ;
} else {
F_5 ( F_4 ( V_7 L_13 ) ) ;
}
if ( V_16 != F_18 ( & V_8 , V_29 ) ) {
F_4 ( V_5 L_14 ) ;
F_12 ( & V_30 ) ;
return 1 ;
}
while( ( V_13 = F_19 ( & V_8 , V_24 ) ) == V_16 )
;
if ( V_13 != V_25 ) {
F_4 ( V_33 L_15 , V_13 ) ;
}
F_20 ( & V_8 ) ;
F_12 ( & V_30 ) ;
return 0 ;
}
int T_1 F_21 ( void )
{
int V_13 ;
V_13 = F_1 () ;
if ( V_13 )
return V_13 ;
V_13 = F_22 ( & V_34 ) ;
if ( V_13 )
F_8 () ;
return V_13 ;
}
void F_23 ( void )
{
F_24 ( & V_34 ) ;
F_8 () ;
}
