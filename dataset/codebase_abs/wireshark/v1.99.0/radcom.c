int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_3 V_4 [ 8 ] , V_5 [ 11 ] , V_6 [ 7 ] ;
struct V_7 V_8 ;
#if 0
guint32 sec;
struct tm tm;
#endif
V_9 = V_10 ;
if ( ! F_2 ( V_1 -> V_11 , V_4 , 8 , V_2 , V_3 ) ) {
if ( * V_2 != V_12 )
return - 1 ;
return 0 ;
}
V_4 [ 1 ] = 0xD2 ;
V_4 [ 2 ] = 0x00 ;
if ( memcmp ( V_4 , V_13 , 8 ) != 0 ) {
return 0 ;
}
V_9 = V_10 ;
if ( ! F_2 ( V_1 -> V_11 , V_5 , 11 , V_2 , V_3 ) ) {
if ( * V_2 == V_12 ) {
return 0 ;
}
return - 1 ;
}
while ( memcmp ( V_5 , V_14 , 11 ) != 0 )
{
if ( F_3 ( V_1 -> V_11 , - 10 , V_15 , V_2 ) == - 1 )
return - 1 ;
V_9 = V_10 ;
if ( ! F_2 ( V_1 -> V_11 , V_5 , 11 , V_2 , V_3 ) ) {
if ( * V_2 == V_12 ) {
return 0 ;
}
return - 1 ;
}
}
if ( F_3 ( V_1 -> V_11 , - 43 , V_15 , V_2 ) == - 1 ) return - 1 ;
V_9 = V_10 ;
if ( ! F_2 ( V_1 -> V_11 , & V_8 , sizeof( struct V_7 ) ,
V_2 , V_3 ) ) {
if ( * V_2 == V_12 ) {
return 0 ;
}
return - 1 ;
}
if ( F_3 ( V_1 -> V_11 , sizeof( struct V_7 ) , V_15 , V_2 ) == - 1 )
return - 1 ;
for (; ; ) {
V_9 = V_10 ;
if ( ! F_2 ( V_1 -> V_11 , V_6 , 4 ,
V_2 , V_3 ) ) {
if ( * V_2 == V_12 ) {
return 0 ;
}
return - 1 ;
}
if ( memcmp ( V_16 , V_6 , 4 ) == 0 )
break;
if ( F_3 ( V_1 -> V_11 , - 3 , V_15 , V_2 ) == - 1 )
return - 1 ;
}
if ( F_3 ( V_1 -> V_11 , 12 , V_15 , V_2 ) == - 1 )
return - 1 ;
V_9 = V_10 ;
if ( ! F_2 ( V_1 -> V_11 , V_6 , 4 , V_2 , V_3 ) ) {
if ( * V_2 == V_12 ) {
return 0 ;
}
return - 1 ;
}
V_1 -> V_17 = V_18 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = 0 ;
V_1 -> V_24 = V_25 ;
#if 0
tm.tm_year = pletoh16(&start_date.year)-1900;
tm.tm_mon = start_date.month-1;
tm.tm_mday = start_date.day;
sec = pletoh32(&start_date.sec);
tm.tm_hour = sec/3600;
tm.tm_min = (sec%3600)/60;
tm.tm_sec = sec%60;
tm.tm_isdst = -1;
#endif
if ( memcmp ( V_6 , L_1 , 4 ) == 0 )
V_1 -> V_26 = V_27 ;
else if ( memcmp ( V_6 , L_2 , 4 ) == 0 )
V_1 -> V_26 = V_28 ;
else if ( memcmp ( V_6 , L_3 , 4 ) == 0 )
V_1 -> V_26 = V_29 ;
else {
* V_2 = V_30 ;
* V_3 = F_4 ( L_4 , V_6 ) ;
return - 1 ;
}
#if 0
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, &next_date, sizeof(struct frame_date),
err, err_info))
return -1;
while (memcmp(&start_date, &next_date, 4)) {
if (file_seek(wth->fh, 1-sizeof(struct frame_date), SEEK_CUR, err) == -1)
return -1;
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, &next_date, sizeof(struct frame_date),
err, err_info))
return -1;
}
#endif
if ( V_1 -> V_26 == V_28 ) {
if ( F_3 ( V_1 -> V_11 , 294 , V_15 , V_2 ) == - 1 )
return - 1 ;
} else if ( V_1 -> V_26 == V_27 ) {
if ( F_3 ( V_1 -> V_11 , 297 , V_15 , V_2 ) == - 1 )
return - 1 ;
} else if ( V_1 -> V_26 == V_29 ) {
if ( F_3 ( V_1 -> V_11 , 504 , V_15 , V_2 ) == - 1 )
return - 1 ;
}
return 1 ;
}
static T_4 V_20 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_5 * V_31 )
{
char V_32 [ 2 ] ;
* V_31 = F_5 ( V_1 -> V_11 ) ;
if ( ! F_6 ( V_1 , V_1 -> V_11 , & V_1 -> V_33 , V_1 -> V_34 ,
V_2 , V_3 ) ) {
return FALSE ;
}
if ( V_1 -> V_26 == V_27 ) {
V_9 = V_10 ;
if ( ! F_2 ( V_1 -> V_11 , & V_32 , sizeof V_32 , V_2 , V_3 ) )
return FALSE ;
}
return TRUE ;
}
static T_4
V_22 ( T_1 * V_1 , T_5 V_35 ,
struct V_36 * V_33 , T_6 * V_37 ,
int * V_2 , T_2 * * V_3 )
{
if ( F_3 ( V_1 -> V_38 , V_35 , V_39 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_6 ( V_1 , V_1 -> V_38 , V_33 , V_37 , V_2 ,
V_3 ) ) {
if ( * V_2 == 0 ) {
* V_2 = V_12 ;
}
return FALSE ;
}
return TRUE ;
}
static T_4
F_6 ( T_1 * V_1 , T_7 V_11 , struct V_36 * V_33 , T_6 * V_37 ,
int * V_2 , T_2 * * V_3 )
{
struct V_40 V_41 ;
T_8 V_42 , V_43 , V_44 ;
T_9 V_45 ;
struct V_46 V_46 ;
T_3 V_47 [ 8 ] ;
V_9 = V_10 ;
if ( ! F_7 ( V_11 , & V_41 , sizeof V_41 , V_2 , V_3 ) )
return FALSE ;
V_42 = F_8 ( & V_41 . V_42 ) ;
if ( V_42 == 0 ) {
* V_2 = 0 ;
return FALSE ;
}
V_44 = F_8 ( & V_41 . V_44 ) ;
V_43 = F_8 ( & V_41 . V_43 ) ;
V_33 -> V_48 = V_49 ;
V_33 -> V_50 = V_51 | V_52 ;
V_46 . V_53 = F_8 ( & V_41 . V_54 . V_55 ) - 1900 ;
V_46 . V_56 = ( V_41 . V_54 . V_57 & 0x0f ) - 1 ;
V_46 . V_58 = V_41 . V_54 . V_59 ;
V_45 = F_9 ( & V_41 . V_54 . V_45 ) ;
V_46 . V_60 = V_45 / 3600 ;
V_46 . V_61 = ( V_45 % 3600 ) / 60 ;
V_46 . V_62 = V_45 % 60 ;
V_46 . V_63 = - 1 ;
V_33 -> V_64 . V_65 = mktime ( & V_46 ) ;
V_33 -> V_64 . V_66 = F_9 ( & V_41 . V_54 . V_67 ) * 1000 ;
switch ( V_1 -> V_26 ) {
case V_28 :
V_33 -> V_68 . V_69 . V_70 = - 1 ;
break;
case V_27 :
V_33 -> V_68 . V_71 . V_72 = ( V_41 . V_73 & 0x1 ) ?
0x00 : V_74 ;
V_44 -= 2 ;
V_43 -= 2 ;
break;
case V_29 :
V_9 = V_10 ;
if ( ! F_2 ( V_11 , V_47 , sizeof V_47 , V_2 ,
V_3 ) )
return FALSE ;
V_44 -= 8 ;
V_43 -= 8 ;
break;
}
V_33 -> V_75 = V_43 ;
V_33 -> V_76 = V_44 ;
if ( ! F_10 ( V_11 , V_37 , V_44 , V_2 , V_3 ) )
return FALSE ;
return TRUE ;
}
