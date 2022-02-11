int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
T_3 V_5 [ 8 ] , V_6 [ 11 ] , V_7 [ 7 ] ;
struct V_8 V_9 ;
#if 0
guint32 sec;
struct tm tm;
#endif
V_10 = V_11 ;
V_4 = F_2 ( V_5 , 8 , V_1 -> V_12 ) ;
if ( V_4 != 8 ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
V_5 [ 1 ] = 0xD2 ;
V_5 [ 2 ] = 0x00 ;
if ( memcmp ( V_5 , V_13 , 8 ) != 0 ) {
return 0 ;
}
V_10 = V_11 ;
V_4 = F_2 ( V_6 , 11 , V_1 -> V_12 ) ;
if ( V_4 != 11 ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
while ( memcmp ( V_6 , V_14 , 11 ) != 0 )
{
if ( F_4 ( V_1 -> V_12 , - 10 , V_15 , V_2 ) == - 1 )
return - 1 ;
V_10 = V_11 ;
V_4 = F_2 ( V_6 , 11 , V_1 -> V_12 ) ;
if ( V_4 != 11 ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
}
if ( F_4 ( V_1 -> V_12 , - 43 , V_15 , V_2 ) == - 1 ) return - 1 ;
V_10 = V_11 ;
V_4 = F_2 ( & V_9 , sizeof( struct V_8 ) ,
V_1 -> V_12 ) ;
if ( V_4 != sizeof( struct V_8 ) ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
V_1 -> V_16 = V_17 ;
V_1 -> V_18 = V_19 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_22 = 0 ;
V_1 -> V_23 = V_24 ;
#if 0
tm.tm_year = pletohs(&start_date.year)-1900;
tm.tm_mon = start_date.month-1;
tm.tm_mday = start_date.day;
sec = pletohl(&start_date.sec);
tm.tm_hour = sec/3600;
tm.tm_min = (sec%3600)/60;
tm.tm_sec = sec%60;
tm.tm_isdst = -1;
#endif
if ( F_4 ( V_1 -> V_12 , sizeof( struct V_8 ) , V_15 , V_2 ) == - 1 )
return - 1 ;
V_10 = V_11 ;
V_4 = F_2 ( V_7 , 4 , V_1 -> V_12 ) ;
if ( V_4 != 4 ) {
goto V_25;
}
while ( memcmp ( V_26 , V_7 , 4 ) ) {
if ( F_4 ( V_1 -> V_12 , - 3 , V_15 , V_2 ) == - 1 )
return - 1 ;
V_10 = V_11 ;
V_4 = F_2 ( V_7 , 4 , V_1 -> V_12 ) ;
if ( V_4 != 4 ) {
goto V_25;
}
}
if ( F_4 ( V_1 -> V_12 , 12 , V_15 , V_2 ) == - 1 )
return - 1 ;
V_10 = V_11 ;
V_4 = F_2 ( V_7 , 4 , V_1 -> V_12 ) ;
if ( V_4 != 4 ) {
goto V_25;
}
if ( memcmp ( V_7 , L_1 , 4 ) == 0 )
V_1 -> V_27 = V_28 ;
else if ( memcmp ( V_7 , L_2 , 4 ) == 0 )
V_1 -> V_27 = V_29 ;
else if ( memcmp ( V_7 , L_3 , 4 ) == 0 )
V_1 -> V_27 = V_30 ;
else {
* V_2 = V_31 ;
* V_3 = F_5 ( L_4 , V_7 ) ;
return - 1 ;
}
#if 0
bytes_read = file_read(&next_date, sizeof(struct frame_date), wth->fh);
errno = WTAP_ERR_CANT_READ;
if (bytes_read != sizeof(struct frame_date)) {
goto read_error;
}
while (memcmp(&start_date, &next_date, 4)) {
if (file_seek(wth->fh, 1-sizeof(struct frame_date), SEEK_CUR, err) == -1)
return -1;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&next_date, sizeof(struct frame_date),
wth->fh);
if (bytes_read != sizeof(struct frame_date)) {
goto read_error;
}
}
#endif
if ( V_1 -> V_27 == V_29 ) {
if ( F_4 ( V_1 -> V_12 , 294 , V_15 , V_2 ) == - 1 )
return - 1 ;
} else if ( V_1 -> V_27 == V_28 ) {
if ( F_4 ( V_1 -> V_12 , 297 , V_15 , V_2 ) == - 1 )
return - 1 ;
} else if ( V_1 -> V_27 == V_30 ) {
if ( F_4 ( V_1 -> V_12 , 504 , V_15 , V_2 ) == - 1 )
return - 1 ;
}
return 1 ;
V_25:
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
static T_4 V_19 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_5 * V_32 )
{
int V_33 ;
struct V_34 V_35 ;
T_6 V_36 , V_37 , V_38 ;
T_7 V_39 ;
int V_4 ;
struct V_40 V_40 ;
T_3 V_41 [ 8 ] ;
char V_42 [ 2 ] ;
* V_32 = F_6 ( V_1 -> V_12 ) ;
V_33 = F_7 ( V_1 -> V_12 , & V_35 , V_2 , V_3 ) ;
if ( V_33 <= 0 ) {
return FALSE ;
}
V_36 = F_8 ( & V_35 . V_36 ) ;
if ( V_36 == 0 ) {
* V_2 = 0 ;
return FALSE ;
}
V_38 = F_8 ( & V_35 . V_38 ) ;
V_37 = F_8 ( & V_35 . V_37 ) ;
if ( V_1 -> V_27 == V_28 ) {
V_38 -= 2 ;
V_37 -= 2 ;
}
V_1 -> V_41 . V_43 = V_44 | V_45 ;
V_1 -> V_41 . V_46 = V_37 ;
V_1 -> V_41 . V_47 = V_38 ;
V_40 . V_48 = F_8 ( & V_35 . V_49 . V_50 ) - 1900 ;
V_40 . V_51 = ( V_35 . V_49 . V_52 & 0x0f ) - 1 ;
V_40 . V_53 = V_35 . V_49 . V_54 ;
V_39 = F_9 ( & V_35 . V_49 . V_39 ) ;
V_40 . V_55 = V_39 / 3600 ;
V_40 . V_56 = ( V_39 % 3600 ) / 60 ;
V_40 . V_57 = V_39 % 60 ;
V_40 . V_58 = - 1 ;
V_1 -> V_41 . V_59 . V_60 = mktime ( & V_40 ) ;
V_1 -> V_41 . V_59 . V_61 = F_9 ( & V_35 . V_49 . V_62 ) * 1000 ;
switch ( V_1 -> V_27 ) {
case V_29 :
V_1 -> V_63 . V_64 . V_65 = - 1 ;
break;
case V_28 :
V_1 -> V_63 . V_66 . V_67 = ( V_35 . V_68 & 0x1 ) ?
0x00 : V_69 ;
break;
case V_30 :
if ( ! F_10 ( V_1 -> V_12 , V_41 , sizeof V_41 , V_2 ,
V_3 ) )
return FALSE ;
V_38 -= 8 ;
V_1 -> V_41 . V_46 -= 8 ;
V_1 -> V_41 . V_47 -= 8 ;
break;
}
F_11 ( V_1 -> V_70 , V_38 ) ;
if ( ! F_10 ( V_1 -> V_12 ,
F_12 ( V_1 -> V_70 ) , V_38 , V_2 , V_3 ) )
return FALSE ;
if ( V_1 -> V_27 == V_28 ) {
V_10 = V_11 ;
V_4 = F_2 ( & V_42 , sizeof V_42 , V_1 -> V_12 ) ;
if ( V_4 != sizeof V_42 ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_71 ;
return FALSE ;
}
}
return TRUE ;
}
static T_4
V_21 ( T_1 * V_1 , T_5 V_72 ,
union V_73 * V_63 , T_3 * V_74 , int V_38 ,
int * V_2 , T_2 * * V_3 )
{
int V_33 ;
struct V_34 V_35 ;
T_3 V_41 [ 8 ] ;
if ( F_4 ( V_1 -> V_75 , V_72 , V_76 , V_2 ) == - 1 )
return FALSE ;
V_33 = F_7 ( V_1 -> V_75 , & V_35 , V_2 , V_3 ) ;
if ( V_33 <= 0 ) {
if ( V_33 == 0 ) {
* V_2 = V_71 ;
}
return FALSE ;
}
switch ( V_1 -> V_27 ) {
case V_29 :
V_63 -> V_64 . V_65 = - 1 ;
break;
case V_28 :
V_63 -> V_66 . V_67 = ( V_35 . V_68 & 0x1 ) ? 0x00 : V_69 ;
break;
case V_30 :
if ( ! F_10 ( V_1 -> V_75 , V_41 , sizeof V_41 ,
V_2 , V_3 ) )
return FALSE ;
break;
}
return F_10 ( V_1 -> V_75 , V_74 , V_38 , V_2 , V_3 ) ;
}
static int
F_7 ( T_8 V_12 , struct V_34 * V_35 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_10 = V_11 ;
V_4 = F_2 ( V_35 , sizeof *V_35 , V_12 ) ;
if ( V_4 != sizeof *V_35 ) {
* V_2 = F_3 ( V_12 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
if ( V_4 != 0 ) {
* V_2 = V_71 ;
return - 1 ;
}
return 0 ;
}
return 1 ;
}
static T_4
F_10 ( T_8 V_12 , T_3 * V_74 , int V_38 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_10 = V_11 ;
V_4 = F_2 ( V_74 , V_38 , V_12 ) ;
if ( V_4 != V_38 ) {
* V_2 = F_3 ( V_12 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_71 ;
return FALSE ;
}
return TRUE ;
}
