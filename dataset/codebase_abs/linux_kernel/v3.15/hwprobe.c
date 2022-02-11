void T_1
F_1 ( T_2 * V_1 , int V_2 )
{
T_3 * V_3 ;
struct V_4 * V_5 ;
char * V_6 ;
char V_7 [ 80 ] ;
char V_8 [ 6 ] = { 0 ,} ;
V_3 = ( T_3 * ) ( F_2 ( V_1 -> V_9 ) ) ;
V_6 = F_3 ( V_3 ) ;
switch ( V_1 -> V_10 ) {
case V_11 :
memcpy ( V_8 , V_1 -> V_12 . V_13 . V_14 , 6 ) ;
break;
case V_15 :
memcpy ( V_8 , V_1 -> V_12 . V_16 . V_14 , 6 ) ;
break;
}
sprintf ( V_7 , L_1 ,
V_1 -> V_17 , V_6 ,
( ( V_8 [ 3 ] << 16 ) & 0xff0000 ) |
( ( V_8 [ 4 ] << 8 ) & 0x00ff00 ) |
( V_8 [ 5 ] & 0x0000ff ) ,
( V_18 ) V_1 -> V_19 [ 0 ] ) ;
F_4 ( L_2 , V_7 ) ;
V_5 = V_1 -> V_5 [ 0 ] ;
F_4 ( L_3 ,
V_1 -> V_17 , L_4 ,
( unsigned long ) V_1 -> V_20 [ 0 ] , V_1 -> V_21 [ 0 ] ,
V_1 -> V_22 , ( V_18 ) F_5 ( V_5 -> V_23 ) ,
( V_18 ) F_6 ( V_5 -> V_23 ) , V_5 -> V_24 ) ;
V_5 = V_1 -> V_5 [ 1 ] ;
F_4 ( L_3 ,
V_1 -> V_17 , L_5 ,
( unsigned long ) V_1 -> V_20 [ 1 ] , V_1 -> V_21 [ 1 ] ,
V_1 -> V_22 , ( V_18 ) F_5 ( V_5 -> V_23 ) ,
( V_18 ) F_6 ( V_5 -> V_23 ) , V_5 -> V_24 ) ;
}
void T_1
F_7 ( T_2 * V_1 , int V_2 )
{
long V_21 ;
V_21 = ( long ) V_1 -> V_20 [ 1 ] + V_25 ;
F_8 ( V_21 , 0 , ( char * ) V_1 -> V_12 . V_26 ,
sizeof( V_27 ) ) ;
#if 0
{
unsigned char *ucp = (unsigned char *) &hi->mfg_info.data;
pr_info("eeprom[00]: %02x %02x %02x %02x %02x %02x %02x %02x\n",
*(ucp + 0), *(ucp + 1), *(ucp + 2), *(ucp + 3),
*(ucp + 4), *(ucp + 5), *(ucp + 6), *(ucp + 7));
pr_info("eeprom[08]: %02x %02x %02x %02x %02x %02x %02x %02x\n",
*(ucp + 8), *(ucp + 9), *(ucp + 10), *(ucp + 11),
*(ucp + 12), *(ucp + 13), *(ucp + 14), *(ucp + 15));
pr_info("eeprom[16]: %02x %02x %02x %02x %02x %02x %02x %02x\n",
*(ucp + 16), *(ucp + 17), *(ucp + 18), *(ucp + 19),
*(ucp + 20), *(ucp + 21), *(ucp + 22), *(ucp + 23));
pr_info("eeprom[24]: %02x %02x %02x %02x %02x %02x %02x %02x\n",
*(ucp + 24), *(ucp + 25), *(ucp + 26), *(ucp + 27),
*(ucp + 28), *(ucp + 29), *(ucp + 30), *(ucp + 31));
pr_info("eeprom[32]: %02x %02x %02x %02x %02x %02x %02x %02x\n",
*(ucp + 32), *(ucp + 33), *(ucp + 34), *(ucp + 35),
*(ucp + 36), *(ucp + 37), *(ucp + 38), *(ucp + 39));
pr_info("eeprom[40]: %02x %02x %02x %02x %02x %02x %02x %02x\n",
*(ucp + 40), *(ucp + 41), *(ucp + 42), *(ucp + 43),
*(ucp + 44), *(ucp + 45), *(ucp + 46), *(ucp + 47));
}
#endif
#if 0
pr_info("sn: %x %x %x %x %x %x\n",
hi->mfg_info.Serial[0],
hi->mfg_info.Serial[1],
hi->mfg_info.Serial[2],
hi->mfg_info.Serial[3],
hi->mfg_info.Serial[4],
hi->mfg_info.Serial[5]);
#endif
V_1 -> V_10 = F_9 ( & V_1 -> V_12 . V_26 ) ;
if ( V_1 -> V_10 == V_28 ) {
if ( V_29 >= V_30 )
F_4 ( L_6 , V_1 -> V_17 ) ;
V_1 -> V_31 = V_32 ;
} else
V_1 -> V_31 = V_33 ;
}
void T_1
F_10 ( void )
{
T_2 * V_1 ;
int V_34 ;
for ( V_34 = 0 , V_1 = V_35 ; V_34 < V_36 ; V_34 ++ , V_1 ++ ) {
V_1 -> V_22 = 0xff ;
V_1 -> V_37 = 0xff ;
V_1 -> V_38 [ 0 ] = 0 ;
V_1 -> V_38 [ 1 ] = 0 ;
V_1 -> V_9 = NULL ;
V_1 -> V_21 [ 0 ] = 0L ;
V_1 -> V_21 [ 1 ] = 0L ;
V_1 -> V_20 [ 0 ] = 0L ;
V_1 -> V_20 [ 1 ] = 0L ;
}
}
void
F_11 ( void )
{
T_2 * V_1 ;
int V_34 ;
for ( V_34 = 0 , V_1 = V_35 ; V_34 < V_36 ; V_34 ++ , V_1 ++ ) {
if ( V_1 -> V_37 == 0xff )
break;
if ( V_1 -> V_20 [ 0 ] ) {
F_12 ( ( void * ) ( V_1 -> V_20 [ 0 ] ) ) ;
F_13 ( ( long ) V_1 -> V_21 [ 0 ] , V_1 -> V_39 [ 0 ] ) ;
V_1 -> V_20 [ 0 ] = 0 ;
}
if ( V_1 -> V_20 [ 1 ] ) {
F_12 ( ( void * ) ( V_1 -> V_20 [ 1 ] ) ) ;
F_13 ( ( long ) V_1 -> V_21 [ 1 ] , V_1 -> V_39 [ 1 ] ) ;
V_1 -> V_20 [ 1 ] = 0 ;
}
}
}
void
F_14 ( void )
{
T_2 * V_1 ;
int V_34 ;
for ( V_34 = 0 , V_1 = V_35 ; V_34 < V_36 ; V_34 ++ , V_1 ++ ) {
if ( V_1 -> V_37 == 0xff || ! V_1 -> V_9 )
break;
F_15 ( F_2 ( V_1 -> V_9 ) ) ;
#ifdef F_16
F_17 ( F_2 ( V_1 -> V_9 ) ) ;
#endif
F_18 ( V_1 -> V_9 ) ;
F_19 ( V_1 -> V_5 [ 0 ] -> V_24 , V_1 -> V_9 ) ;
#ifdef F_20
F_19 ( V_1 -> V_5 [ 1 ] -> V_24 , V_1 -> V_9 ) ;
#endif
F_21 ( V_1 -> V_9 ) ;
}
}
static int T_1
F_22 ( struct V_4 * V_5 , int V_40 )
{
T_2 * V_1 ;
int V_34 ;
int V_41 , V_42 ;
unsigned char V_43 = 0xff ;
V_41 = F_6 ( V_5 -> V_23 ) ;
if ( V_41 > 1 ) {
F_23 ( L_7 , V_5 -> V_23 ) ;
return 0 ;
}
if ( V_5 -> V_44 )
V_43 = V_5 -> V_44 -> V_45 ;
else
V_43 = 0 ;
V_42 = V_5 -> V_23 & ~ 0x07 ;
for ( V_34 = 0 , V_1 = V_35 ; V_34 < V_36 ; V_34 ++ , V_1 ++ ) {
if ( ( V_1 -> V_37 == 0xff ) ||
( ( V_1 -> V_37 == V_42 ) && ( V_1 -> V_44 == V_5 -> V_44 ) ) )
break;
}
if ( V_34 == V_36 ) {
F_23 ( L_8 ,
V_36 ) ;
return 0 ;
}
if ( V_5 -> V_44 )
V_1 -> V_22 = V_5 -> V_44 -> V_45 ;
else
V_1 -> V_22 = 0 ;
V_1 -> V_37 = V_42 ;
F_24 ( V_5 , V_46 , & V_1 -> V_38 [ V_41 ] ) ;
F_24 ( V_5 , V_47 , & V_1 -> V_19 [ V_41 ] ) ;
V_1 -> V_44 = V_5 -> V_44 ;
V_1 -> V_21 [ V_41 ] = F_25 ( V_5 , 0 ) ;
V_1 -> V_39 [ V_41 ] = F_26 ( V_5 , 0 ) - V_1 -> V_21 [ V_41 ] + 1 ;
V_1 -> V_5 [ V_41 ] = V_5 ;
{
char * V_48 = V_1 -> V_17 ;
strcpy ( V_48 , V_49 ) ;
V_48 += strlen ( V_48 ) ;
* V_48 ++ = '-' ;
* V_48 ++ = '0' + ( V_40 / 2 ) ;
* V_48 = 0 ;
}
return 1 ;
}
T_4 T_1
F_27 ( void )
{
T_2 * V_1 ;
struct V_4 * V_5 = NULL ;
int V_40 = 0 , V_34 , V_50 ;
V_51 = 0 ;
F_10 () ;
while ( ( V_5 = F_28 ( V_52 ,
V_53 ,
V_5 ) ) ) {
if ( F_22 ( V_5 , V_40 ) )
V_40 ++ ;
}
if ( ! V_40 ) {
F_23 ( L_9 ) ;
return - V_54 ;
}
for ( V_34 = 0 , V_1 = V_35 ; V_34 < V_36 ; V_34 ++ , V_1 ++ ) {
if ( V_1 -> V_37 != 0xff && ( ! V_1 -> V_21 [ 0 ] || ! V_1 -> V_21 [ 1 ] ) ) {
F_23 ( L_10 ,
V_1 -> V_17 ) ;
return - V_55 ;
}
}
for ( V_34 = 0 , V_1 = V_35 ; V_34 < V_36 ; V_34 ++ , V_1 ++ ) {
if ( V_1 -> V_37 == 0xff )
break;
for ( V_50 = 0 ; V_50 < 2 ; V_50 ++ ) {
if ( ! F_29 ( V_1 -> V_21 [ V_50 ] , V_1 -> V_39 [ V_50 ] , V_1 -> V_17 ) ) {
F_23 ( L_11 ,
V_1 -> V_17 , V_1 -> V_21 [ V_50 ] , V_1 -> V_39 [ V_50 ] ) ;
F_11 () ;
return - V_56 ;
}
V_1 -> V_20 [ V_50 ] = ( unsigned long ) F_30 ( V_1 -> V_21 [ V_50 ] , V_1 -> V_39 [ V_50 ] ) ;
if ( ! V_1 -> V_20 [ V_50 ] ) {
F_23 ( L_12 ,
V_1 -> V_17 , V_1 -> V_21 [ V_50 ] , V_1 -> V_39 [ V_50 ] ) ;
F_11 () ;
return - V_56 ;
}
#ifdef F_31
F_23 ( L_13 ,
V_1 -> V_17 , ( V_57 ) V_1 -> V_21 [ V_50 ] ,
( V_57 ) V_1 -> V_20 [ V_50 ] ) ;
#endif
}
}
V_58 = V_59 ;
for ( V_34 = 0 , V_1 = V_35 ; V_34 < V_36 ; V_34 ++ , V_1 ++ ) {
if ( V_1 -> V_37 == 0xff )
break;
if ( F_32 ( V_1 -> V_5 [ 0 ] ) ||
F_32 ( V_1 -> V_5 [ 1 ] ) ) {
V_58 = V_60 ;
F_23 ( L_14 ,
V_1 -> V_17 , V_34 , V_1 -> V_37 ) ;
F_14 () ;
F_11 () ;
return - V_55 ;
}
F_33 ( V_1 -> V_5 [ 0 ] ) ;
F_33 ( V_1 -> V_5 [ 1 ] ) ;
V_1 -> V_9 = F_34 ( V_1 , V_34 , ( long ) V_1 -> V_20 [ 0 ] ,
( long ) V_1 -> V_20 [ 1 ] ,
V_1 -> V_5 [ 0 ] -> V_24 ,
V_1 -> V_5 [ 1 ] -> V_24 ) ;
if ( ! V_1 -> V_9 ) {
V_58 = V_60 ;
F_11 () ;
#if 0
cleanup_devs();
#endif
return V_51 ;
}
F_1 ( V_1 , V_34 ) ;
}
return 0 ;
}
