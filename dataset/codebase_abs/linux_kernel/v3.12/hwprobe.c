void T_1
F_1 ( T_2 * V_1 , int V_2 )
{
T_3 * V_3 ;
struct V_4 * V_5 ;
char * V_6 ;
char * V_7 , V_8 [ 80 ] ;
char V_9 [ 6 ] ;
V_7 = V_8 ;
memset ( V_8 , 0 , 80 ) ;
V_3 = ( T_3 * ) ( F_2 ( V_1 -> V_10 ) ) ;
V_6 = F_3 ( V_3 ) ;
switch ( V_1 -> V_11 )
{
case V_12 :
memcpy ( V_9 , ( V_13 * ) ( V_1 -> V_14 . V_15 . V_16 ) , 6 ) ;
break;
case V_17 :
memcpy ( V_9 , ( V_18 * ) ( V_1 -> V_14 . V_19 . V_16 ) , 6 ) ;
break;
default:
memset ( V_9 , 0 , 6 ) ;
break;
}
sprintf ( V_8 , L_1 ,
V_1 -> V_20 , V_6 ,
( ( V_9 [ 3 ] << 16 ) & 0xff0000 ) |
( ( V_9 [ 4 ] << 8 ) & 0x00ff00 ) |
( V_9 [ 5 ] & 0x0000ff ) ,
( V_21 ) V_1 -> V_22 [ 0 ] ) ;
F_4 ( L_2 , V_8 ) ;
V_5 = V_1 -> V_5 [ 0 ] ;
F_4 ( L_3 ,
V_1 -> V_20 , L_4 ,
( unsigned long ) V_1 -> V_23 [ 0 ] , V_1 -> V_24 [ 0 ] ,
V_1 -> V_25 , ( V_21 ) F_5 ( V_5 -> V_26 ) ,
( V_21 ) F_6 ( V_5 -> V_26 ) , V_5 -> V_27 ) ;
V_5 = V_1 -> V_5 [ 1 ] ;
F_4 ( L_3 ,
V_1 -> V_20 , L_5 ,
( unsigned long ) V_1 -> V_23 [ 1 ] , V_1 -> V_24 [ 1 ] ,
V_1 -> V_25 , ( V_21 ) F_5 ( V_5 -> V_26 ) ,
( V_21 ) F_6 ( V_5 -> V_26 ) , V_5 -> V_27 ) ;
}
void T_1
F_7 ( T_2 * V_1 , int V_2 )
{
long V_24 ;
V_24 = ( long ) V_1 -> V_23 [ 1 ] + V_28 ;
F_8 ( V_24 , 0 , ( char * ) V_1 -> V_14 . V_29 , sizeof ( V_18 ) ) ;
#if 0
{
unsigned char *ucp = (unsigned char *) &hi->mfg_info.data;
pr_info("eeprom[00]: %02x %02x %02x %02x %02x %02x %02x %02x\n",
*(ucp + 0), *(ucp + 1), *(ucp + 2), *(ucp + 3), *(ucp + 4), *(ucp + 5), *(ucp + 6), *(ucp + 7));
pr_info("eeprom[08]: %02x %02x %02x %02x %02x %02x %02x %02x\n",
*(ucp + 8), *(ucp + 9), *(ucp + 10), *(ucp + 11), *(ucp + 12), *(ucp + 13), *(ucp + 14), *(ucp + 15));
pr_info("eeprom[16]: %02x %02x %02x %02x %02x %02x %02x %02x\n",
*(ucp + 16), *(ucp + 17), *(ucp + 18), *(ucp + 19), *(ucp + 20), *(ucp + 21), *(ucp + 22), *(ucp + 23));
pr_info("eeprom[24]: %02x %02x %02x %02x %02x %02x %02x %02x\n",
*(ucp + 24), *(ucp + 25), *(ucp + 26), *(ucp + 27), *(ucp + 28), *(ucp + 29), *(ucp + 30), *(ucp + 31));
pr_info("eeprom[32]: %02x %02x %02x %02x %02x %02x %02x %02x\n",
*(ucp + 32), *(ucp + 33), *(ucp + 34), *(ucp + 35), *(ucp + 36), *(ucp + 37), *(ucp + 38), *(ucp + 39));
pr_info("eeprom[40]: %02x %02x %02x %02x %02x %02x %02x %02x\n",
*(ucp + 40), *(ucp + 41), *(ucp + 42), *(ucp + 43), *(ucp + 44), *(ucp + 45), *(ucp + 46), *(ucp + 47));
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
if ( ( V_1 -> V_11 = F_9 ( & V_1 -> V_14 . V_29 ) ) == V_30 )
{
if ( V_31 >= V_32 )
F_4 ( L_6 , V_1 -> V_20 ) ;
V_1 -> V_33 = V_34 ;
} else
V_1 -> V_33 = V_35 ;
}
void T_1
F_10 ( void )
{
T_2 * V_1 ;
int V_36 ;
for ( V_36 = 0 , V_1 = V_37 ; V_36 < V_38 ; V_36 ++ , V_1 ++ )
{
V_1 -> V_25 = 0xff ;
V_1 -> V_39 = 0xff ;
V_1 -> V_40 [ 0 ] = 0 ;
V_1 -> V_40 [ 1 ] = 0 ;
V_1 -> V_10 = 0 ;
V_1 -> V_24 [ 0 ] = 0L ;
V_1 -> V_24 [ 1 ] = 0L ;
V_1 -> V_23 [ 0 ] = 0L ;
V_1 -> V_23 [ 1 ] = 0L ;
}
}
void
F_11 ( void )
{
T_2 * V_1 ;
int V_36 ;
for ( V_36 = 0 , V_1 = V_37 ; V_36 < V_38 ; V_36 ++ , V_1 ++ )
{
if ( V_1 -> V_39 == 0xff )
break;
if ( V_1 -> V_23 [ 0 ] )
{
F_12 ( ( void * ) ( V_1 -> V_23 [ 0 ] ) ) ;
F_13 ( ( long ) V_1 -> V_24 [ 0 ] , V_1 -> V_41 [ 0 ] ) ;
V_1 -> V_23 [ 0 ] = 0 ;
}
if ( V_1 -> V_23 [ 1 ] )
{
F_12 ( ( void * ) ( V_1 -> V_23 [ 1 ] ) ) ;
F_13 ( ( long ) V_1 -> V_24 [ 1 ] , V_1 -> V_41 [ 1 ] ) ;
V_1 -> V_23 [ 1 ] = 0 ;
}
}
}
void
F_14 ( void )
{
T_2 * V_1 ;
int V_36 ;
for ( V_36 = 0 , V_1 = V_37 ; V_36 < V_38 ; V_36 ++ , V_1 ++ )
{
if ( V_1 -> V_39 == 0xff || ! V_1 -> V_10 )
break;
F_15 ( F_2 ( V_1 -> V_10 ) ) ;
#ifdef F_16
F_17 ( F_2 ( V_1 -> V_10 ) ) ;
#endif
F_18 ( V_1 -> V_10 ) ;
F_19 ( V_1 -> V_5 [ 0 ] -> V_27 , V_1 -> V_10 ) ;
#ifdef F_20
F_19 ( V_1 -> V_5 [ 1 ] -> V_27 , V_1 -> V_10 ) ;
#endif
F_21 ( V_1 -> V_10 ) ;
}
}
static int T_1
F_22 ( struct V_4 * V_5 , int V_42 )
{
T_2 * V_1 ;
int V_36 ;
int V_43 , V_44 ;
unsigned char V_45 = 0xff ;
if ( ( V_43 = F_6 ( V_5 -> V_26 ) ) > 1 )
{
F_23 ( L_7 , V_5 -> V_26 ) ;
return 0 ;
}
if ( V_5 -> V_46 )
V_45 = V_5 -> V_46 -> V_47 ;
else
V_45 = 0 ;
V_44 = V_5 -> V_26 & ~ 0x07 ;
for ( V_36 = 0 , V_1 = V_37 ; V_36 < V_38 ; V_36 ++ , V_1 ++ )
{
if ( ( V_1 -> V_39 == 0xff ) ||
( ( V_1 -> V_39 == V_44 ) && ( V_1 -> V_46 == V_5 -> V_46 ) ) )
break;
}
if ( V_36 == V_38 )
{
F_23 ( L_8 , V_38 ) ;
return 0 ;
}
if ( V_5 -> V_46 )
V_1 -> V_25 = V_5 -> V_46 -> V_47 ;
else
V_1 -> V_25 = 0 ;
V_1 -> V_39 = V_44 ;
F_24 ( V_5 , V_48 , & V_1 -> V_40 [ V_43 ] ) ;
F_24 ( V_5 , V_49 , & V_1 -> V_22 [ V_43 ] ) ;
V_1 -> V_46 = V_5 -> V_46 ;
V_1 -> V_24 [ V_43 ] = F_25 ( V_5 , 0 ) ;
V_1 -> V_41 [ V_43 ] = F_26 ( V_5 , 0 ) - V_1 -> V_24 [ V_43 ] + 1 ;
V_1 -> V_5 [ V_43 ] = V_5 ;
{
char * V_50 = V_1 -> V_20 ;
strcpy ( V_50 , V_51 ) ;
V_50 += strlen ( V_50 ) ;
* V_50 ++ = '-' ;
* V_50 ++ = '0' + ( V_42 / 2 ) ;
* V_50 = 0 ;
}
return 1 ;
}
T_4 T_1
F_27 ( void )
{
T_2 * V_1 ;
struct V_4 * V_5 = NULL ;
int V_42 = 0 , V_36 , V_52 ;
V_53 = 0 ;
F_10 () ;
while ( ( V_5 = F_28 ( V_54 ,
V_55 ,
V_5 ) ) )
{
if ( F_22 ( V_5 , V_42 ) )
V_42 ++ ;
}
if ( ! V_42 )
{
F_23 ( L_9 ) ;
return V_56 ;
}
for ( V_36 = 0 , V_1 = V_37 ; V_36 < V_38 ; V_36 ++ , V_1 ++ )
{
if ( V_1 -> V_39 != 0xff && ( ! V_1 -> V_24 [ 0 ] || ! V_1 -> V_24 [ 1 ] ) )
{
F_23 ( L_10 ,
V_1 -> V_20 ) ;
return V_57 ;
}
}
for ( V_36 = 0 , V_1 = V_37 ; V_36 < V_38 ; V_36 ++ , V_1 ++ )
{
if ( V_1 -> V_39 == 0xff )
break;
for ( V_52 = 0 ; V_52 < 2 ; V_52 ++ )
{
if ( F_29 ( V_1 -> V_24 [ V_52 ] , V_1 -> V_41 [ V_52 ] , V_1 -> V_20 ) == 0 )
{
F_23 ( L_11 ,
V_1 -> V_20 , V_1 -> V_24 [ V_52 ] , V_1 -> V_41 [ V_52 ] ) ;
F_11 () ;
return V_58 ;
}
V_1 -> V_23 [ V_52 ] = ( unsigned long ) F_30 ( V_1 -> V_24 [ V_52 ] , V_1 -> V_41 [ V_52 ] ) ;
if ( ! V_1 -> V_23 [ V_52 ] )
{
F_23 ( L_12 ,
V_1 -> V_20 , V_1 -> V_24 [ V_52 ] , V_1 -> V_41 [ V_52 ] ) ;
F_11 () ;
return V_58 ;
}
#ifdef F_31
F_23 ( L_13 ,
V_1 -> V_20 , ( V_59 ) V_1 -> V_24 [ V_52 ] , ( V_59 ) V_1 -> V_23 [ V_52 ] ) ;
#endif
}
}
V_60 = V_61 ;
for ( V_36 = 0 , V_1 = V_37 ; V_36 < V_38 ; V_36 ++ , V_1 ++ )
{
if ( V_1 -> V_39 == 0xff )
break;
if ( F_32 ( V_1 -> V_5 [ 0 ] ) ||
F_32 ( V_1 -> V_5 [ 1 ] ) )
{
V_60 = V_62 ;
F_23 ( L_14 ,
V_1 -> V_20 , V_36 , V_1 -> V_39 ) ;
F_14 () ;
F_11 () ;
return V_57 ;
}
F_33 ( V_1 -> V_5 [ 0 ] ) ;
F_33 ( V_1 -> V_5 [ 1 ] ) ;
if ( ! ( V_1 -> V_10 = F_34 ( V_1 , V_36 , ( long ) V_1 -> V_23 [ 0 ] ,
( long ) V_1 -> V_23 [ 1 ] ,
V_1 -> V_5 [ 0 ] -> V_27 ,
V_1 -> V_5 [ 1 ] -> V_27 ) ) )
{
V_60 = V_62 ;
F_11 () ;
#if 0
cleanup_devs ();
#endif
return V_53 ;
}
F_1 ( V_1 , V_36 ) ;
}
return 0 ;
}
