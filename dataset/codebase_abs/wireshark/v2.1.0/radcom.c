T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
T_4 V_4 [ 8 ] , V_5 [ 11 ] , V_6 [ 7 ] ;
struct V_7 V_8 ;
#if 0
guint32 sec;
struct tm tm;
#endif
if ( ! F_2 ( V_1 -> V_9 , V_4 , 8 , V_2 , V_3 ) ) {
if ( * V_2 != V_10 )
return V_11 ;
return V_12 ;
}
V_4 [ 1 ] = 0xD2 ;
V_4 [ 2 ] = 0x00 ;
if ( memcmp ( V_4 , V_13 , 8 ) != 0 ) {
return V_12 ;
}
if ( ! F_2 ( V_1 -> V_9 , V_5 , 11 , V_2 , V_3 ) ) {
if ( * V_2 != V_10 )
return V_11 ;
return V_12 ;
}
while ( memcmp ( V_5 , V_14 , 11 ) != 0 )
{
if ( F_3 ( V_1 -> V_9 , - 10 , V_15 , V_2 ) == - 1 )
return V_11 ;
if ( ! F_2 ( V_1 -> V_9 , V_5 , 11 , V_2 , V_3 ) ) {
if ( * V_2 != V_10 )
return V_11 ;
return V_12 ;
}
}
if ( F_3 ( V_1 -> V_9 , - 43 , V_15 , V_2 ) == - 1 )
return V_11 ;
if ( ! F_2 ( V_1 -> V_9 , & V_8 , sizeof( struct V_7 ) ,
V_2 , V_3 ) ) {
if ( * V_2 != V_10 )
return V_11 ;
return V_12 ;
}
if ( F_3 ( V_1 -> V_9 , sizeof( struct V_7 ) , V_15 , V_2 ) == - 1 )
return V_11 ;
for (; ; ) {
if ( ! F_2 ( V_1 -> V_9 , V_6 , 4 ,
V_2 , V_3 ) ) {
if ( * V_2 != V_10 )
return V_11 ;
return V_12 ;
}
if ( memcmp ( V_16 , V_6 , 4 ) == 0 )
break;
if ( F_3 ( V_1 -> V_9 , - 3 , V_15 , V_2 ) == - 1 )
return V_11 ;
}
if ( F_3 ( V_1 -> V_9 , 12 , V_15 , V_2 ) == - 1 )
return V_11 ;
if ( ! F_2 ( V_1 -> V_9 , V_6 , 4 , V_2 , V_3 ) ) {
if ( * V_2 != V_10 )
return V_11 ;
return V_12 ;
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
return V_11 ;
}
#if 0
if (!wtap_read_bytes(wth->fh, &next_date, sizeof(struct frame_date),
err, err_info))
return WTAP_OPEN_ERROR;
while (memcmp(&start_date, &next_date, 4)) {
if (file_seek(wth->fh, 1-sizeof(struct frame_date), SEEK_CUR, err) == -1)
return WTAP_OPEN_ERROR;
if (!wtap_read_bytes(wth->fh, &next_date, sizeof(struct frame_date),
err, err_info))
return WTAP_OPEN_ERROR;
}
#endif
if ( V_1 -> V_26 == V_28 ) {
if ( F_3 ( V_1 -> V_9 , 294 , V_15 , V_2 ) == - 1 )
return V_11 ;
} else if ( V_1 -> V_26 == V_27 ) {
if ( F_3 ( V_1 -> V_9 , 297 , V_15 , V_2 ) == - 1 )
return V_11 ;
} else if ( V_1 -> V_26 == V_29 ) {
if ( F_3 ( V_1 -> V_9 , 504 , V_15 , V_2 ) == - 1 )
return V_11 ;
}
return V_31 ;
}
static T_5 V_20 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_6 * V_32 )
{
char V_33 [ 2 ] ;
* V_32 = F_5 ( V_1 -> V_9 ) ;
if ( ! F_6 ( V_1 , V_1 -> V_9 , & V_1 -> V_34 , V_1 -> V_35 ,
V_2 , V_3 ) ) {
return FALSE ;
}
if ( V_1 -> V_26 == V_27 ) {
if ( ! F_2 ( V_1 -> V_9 , & V_33 , sizeof V_33 , V_2 , V_3 ) )
return FALSE ;
}
return TRUE ;
}
static T_5
V_22 ( T_2 * V_1 , T_6 V_36 ,
struct V_37 * V_34 , T_7 * V_38 ,
int * V_2 , T_3 * * V_3 )
{
if ( F_3 ( V_1 -> V_39 , V_36 , V_40 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_6 ( V_1 , V_1 -> V_39 , V_34 , V_38 , V_2 ,
V_3 ) ) {
if ( * V_2 == 0 ) {
* V_2 = V_10 ;
}
return FALSE ;
}
return TRUE ;
}
static T_5
F_6 ( T_2 * V_1 , T_8 V_9 , struct V_37 * V_34 , T_7 * V_38 ,
int * V_2 , T_3 * * V_3 )
{
struct V_41 V_42 ;
T_9 V_43 , V_44 , V_45 ;
T_10 V_46 ;
struct V_47 V_47 ;
T_4 V_48 [ 8 ] ;
if ( ! F_7 ( V_9 , & V_42 , sizeof V_42 , V_2 , V_3 ) )
return FALSE ;
V_43 = F_8 ( & V_42 . V_43 ) ;
if ( V_43 == 0 ) {
* V_2 = 0 ;
return FALSE ;
}
V_45 = F_8 ( & V_42 . V_45 ) ;
V_44 = F_8 ( & V_42 . V_44 ) ;
V_34 -> V_49 = V_50 ;
V_34 -> V_51 = V_52 | V_53 ;
V_47 . V_54 = F_8 ( & V_42 . V_55 . V_56 ) - 1900 ;
V_47 . V_57 = ( V_42 . V_55 . V_58 & 0x0f ) - 1 ;
V_47 . V_59 = V_42 . V_55 . V_60 ;
V_46 = F_9 ( & V_42 . V_55 . V_46 ) ;
V_47 . V_61 = V_46 / 3600 ;
V_47 . V_62 = ( V_46 % 3600 ) / 60 ;
V_47 . V_63 = V_46 % 60 ;
V_47 . V_64 = - 1 ;
V_34 -> V_65 . V_66 = mktime ( & V_47 ) ;
V_34 -> V_65 . V_67 = F_9 ( & V_42 . V_55 . V_68 ) * 1000 ;
switch ( V_1 -> V_26 ) {
case V_28 :
V_34 -> V_69 . V_70 . V_71 = - 1 ;
break;
case V_27 :
V_34 -> V_69 . V_72 . V_73 = ( V_42 . V_74 & 0x1 ) ?
0x00 : V_75 ;
V_45 -= 2 ;
V_44 -= 2 ;
break;
case V_29 :
if ( ! F_2 ( V_9 , V_48 , sizeof V_48 , V_2 ,
V_3 ) )
return FALSE ;
V_45 -= 8 ;
V_44 -= 8 ;
break;
}
V_34 -> V_76 = V_44 ;
V_34 -> V_77 = V_45 ;
if ( ! F_10 ( V_9 , V_38 , V_45 , V_2 , V_3 ) )
return FALSE ;
return TRUE ;
}
