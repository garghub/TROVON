void
F_1 ( T_1 * V_1 )
{
if ( V_1 -> V_2 )
{
char V_3 [ 7 + V_4 + 1 ] ;
snprintf ( V_3 , sizeof( V_3 ) , L_1 , V_1 -> V_5 ) ;
F_2 ( L_2 , V_1 -> V_2 ) ;
F_2 ( V_3 , NULL ) ;
V_1 -> V_2 = NULL ;
}
}
static int
F_3 ( char * V_6 , char * * V_7 , T_2 V_8 ,
int V_9 , int * V_10 , void * V_11 )
{
T_1 * V_1 = ( T_1 * ) V_11 ;
int V_12 = 0 ;
char * V_13 ;
struct V_14 * V_15 ;
if ( ! ( V_15 = F_4 ( sizeof ( struct V_14 ) ) ) )
{
return - V_16 ;
}
#if 0
pr_info(">> sbecom_proc_get_sbe_info: entered, offset %d. length %d.\n",
(int) offset, (int) length);
#endif
{
T_3 * V_17 = & V_18 [ V_1 -> V_19 ] ;
T_4 * V_20 = 0 ;
switch ( V_17 -> V_21 )
{
case V_22 :
V_20 = ( T_4 * ) V_17 -> V_23 . V_24 . V_25 ;
break;
case V_26 :
V_20 = ( T_4 * ) V_17 -> V_23 . V_27 . V_25 ;
break;
}
F_5 ( V_1 , V_15 , V_20 ) ;
}
#if 0
pr_info(">> sbecom_get_brdinfo: returned, first_if %p <%s> last_if %p <%s>\n",
(char *) &bip->first_iname, (char *) &bip->first_iname,
(char *) &bip->last_iname, (char *) &bip->last_iname);
#endif
V_12 += sprintf ( V_6 + V_12 , L_3 ) ;
switch ( V_15 -> V_28 )
{
case F_6 ( V_29 , V_30 ) :
V_12 += sprintf ( V_6 + V_12 , L_4 ) ;
break;
case F_6 ( V_29 , V_31 ) :
V_12 += sprintf ( V_6 + V_12 , L_5 ) ;
break;
case F_6 ( V_29 , V_32 ) :
V_12 += sprintf ( V_6 + V_12 , L_6 ) ;
break;
case F_6 ( V_29 , V_33 ) :
V_12 += sprintf ( V_6 + V_12 , L_7 ) ;
break;
case F_6 ( V_29 , V_34 ) :
case F_6 ( V_29 , V_35 ) :
V_12 += sprintf ( V_6 + V_12 , L_8 ) ;
break;
case F_6 ( V_29 , V_36 ) :
case F_6 ( V_29 , V_37 ) :
V_12 += sprintf ( V_6 + V_12 , L_9 ) ;
break;
case F_6 ( V_29 , V_38 ) :
case F_6 ( V_29 , V_39 ) :
V_12 += sprintf ( V_6 + V_12 , L_10 ) ;
break;
case F_6 ( V_29 , V_40 ) :
V_12 += sprintf ( V_6 + V_12 , L_11 ) ;
break;
case F_6 ( V_29 , V_41 ) :
V_12 += sprintf ( V_6 + V_12 , L_12 ) ;
break;
case F_6 ( V_29 , V_42 ) :
V_12 += sprintf ( V_6 + V_12 , L_13 ) ;
break;
default:
V_12 += sprintf ( V_6 + V_12 , L_14 ) ;
break;
}
V_12 += sprintf ( V_6 + V_12 , L_15 , V_15 -> V_28 ) ;
V_12 += sprintf ( V_6 + V_12 , L_16 , V_15 -> V_19 ) ;
V_12 += sprintf ( V_6 + V_12 , L_17 , V_1 -> V_43 ) ;
V_12 += sprintf ( V_6 + V_12 , L_18 , V_15 -> V_44 ) ;
V_12 += sprintf ( V_6 + V_12 , L_19 ,
V_15 -> V_45 ) ;
V_12 += sprintf ( V_6 + V_12 , L_20 , V_1 -> V_46 ) ;
V_12 += sprintf ( V_6 + V_12 , L_21 , V_15 -> V_47 ) ;
#if 1
V_12 += sprintf ( V_6 + V_12 , L_22 ,
( char * ) & V_15 -> V_48 , ( char * ) & V_15 -> V_49 ) ;
#else
V_12 += sprintf ( V_6 + V_12 , L_23 ,
( char * ) & V_15 -> V_48 , ( char * ) & V_15 -> V_49 ) ;
#endif
switch ( V_15 -> V_50 )
{
case V_51 :
V_13 = L_24 ;
break;
case V_52 :
V_13 = L_25 ;
break;
default:
V_13 = L_26 ;
break;
}
V_12 += sprintf ( V_6 + V_12 , L_27 , V_13 ) ;
V_12 += sprintf ( V_6 + V_12 , L_28 , V_1 -> V_53 ) ;
#ifdef F_7
{
extern int V_54 ;
#if 0
extern int max_chans_used;
extern int cxt1e1_max_mtu;
#endif
extern int V_55 , V_56 ;
V_12 += sprintf ( V_6 + V_12 , L_29 , V_54 ) ;
#if 0
len += sprintf (buffer + len, "\nmax_chans_used: %d\n", max_chans_used);
len += sprintf (buffer + len, "cxt1e1_max_mtu: %d\n", cxt1e1_max_mtu);
#endif
V_12 += sprintf ( V_6 + V_12 , L_30 , V_55 ) ;
V_12 += sprintf ( V_6 + V_12 , L_31 , V_56 ) ;
}
#endif
F_8 ( V_15 ) ;
#if 1
* V_10 = 1 ;
#endif
#if 0
if (len <= offset + length)
*eof = 1;
*start = buffer + offset;
len -= offset;
if (len > length)
len = length;
if (len < 0)
len = 0;
#endif
#if 0
{
off_t begin = 0;
int size = 0;
off_t pos = 0;
size = len;
pos = begin + size;
if (pos < offset)
{
len = 0;
begin = pos;
}
*start = buffer + (offset - begin);
len -= (offset - begin);
if (len > length)
len = length;
}
#endif
#if 0
len = strlen (buffer);
*start = NULL;
if (offset + length >= len)
*eof = 1;
else
*eof = 0;
#endif
#if 0
pr_info(">> proc_fs: returned len = %d., start %p\n", len, start);
#endif
return V_12 ;
}
int T_5
F_9 ( T_1 * V_1 )
{
struct V_57 * V_58 ;
char V_3 [ 7 + V_4 + 1 ] ;
snprintf ( V_3 , sizeof( V_3 ) , L_1 , V_1 -> V_5 ) ;
V_1 -> V_2 = F_10 ( V_3 , NULL ) ;
if ( ! V_1 -> V_2 )
{
F_11 ( L_32 , V_1 -> V_5 ) ;
goto V_59;
}
V_58 = F_12 ( L_2 , V_60 | V_61 ,
V_1 -> V_2 , F_3 , V_1 ) ;
if ( ! V_58 )
{
F_11 ( L_33 , V_1 -> V_5 ) ;
goto V_59;
}
return 0 ;
V_59:
F_1 ( V_1 ) ;
return 1 ;
}
void
F_1 ( T_1 * V_1 )
{
}
int T_5
F_9 ( T_1 * V_1 )
{
return 0 ;
}
