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
if ( * V_2 != 0 && * V_2 != V_13 )
return - 1 ;
return 0 ;
}
V_5 [ 1 ] = 0xD2 ;
V_5 [ 2 ] = 0x00 ;
if ( memcmp ( V_5 , V_14 , 8 ) != 0 ) {
return 0 ;
}
V_10 = V_11 ;
V_4 = F_2 ( V_6 , 11 , V_1 -> V_12 ) ;
if ( V_4 != 11 ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_13 )
return - 1 ;
return 0 ;
}
while ( memcmp ( V_6 , V_15 , 11 ) != 0 )
{
if ( F_4 ( V_1 -> V_12 , - 10 , V_16 , V_2 ) == - 1 )
return - 1 ;
V_10 = V_11 ;
V_4 = F_2 ( V_6 , 11 , V_1 -> V_12 ) ;
if ( V_4 != 11 ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_13 )
return - 1 ;
return 0 ;
}
}
if ( F_4 ( V_1 -> V_12 , - 43 , V_16 , V_2 ) == - 1 ) return - 1 ;
V_10 = V_11 ;
V_4 = F_2 ( & V_9 , sizeof( struct V_8 ) ,
V_1 -> V_12 ) ;
if ( V_4 != sizeof( struct V_8 ) ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_13 )
return - 1 ;
return 0 ;
}
V_1 -> V_17 = V_18 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = 0 ;
V_1 -> V_24 = V_25 ;
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
if ( F_4 ( V_1 -> V_12 , sizeof( struct V_8 ) , V_16 , V_2 ) == - 1 )
return - 1 ;
V_10 = V_11 ;
V_4 = F_2 ( V_7 , 4 , V_1 -> V_12 ) ;
if ( V_4 != 4 ) {
goto V_26;
}
while ( memcmp ( V_27 , V_7 , 4 ) ) {
if ( F_4 ( V_1 -> V_12 , - 3 , V_16 , V_2 ) == - 1 )
return - 1 ;
V_10 = V_11 ;
V_4 = F_2 ( V_7 , 4 , V_1 -> V_12 ) ;
if ( V_4 != 4 ) {
goto V_26;
}
}
if ( F_4 ( V_1 -> V_12 , 12 , V_16 , V_2 ) == - 1 )
return - 1 ;
V_10 = V_11 ;
V_4 = F_2 ( V_7 , 4 , V_1 -> V_12 ) ;
if ( V_4 != 4 ) {
goto V_26;
}
if ( memcmp ( V_7 , L_1 , 4 ) == 0 )
V_1 -> V_28 = V_29 ;
else if ( memcmp ( V_7 , L_2 , 4 ) == 0 )
V_1 -> V_28 = V_30 ;
else if ( memcmp ( V_7 , L_3 , 4 ) == 0 )
V_1 -> V_28 = V_31 ;
else {
* V_2 = V_32 ;
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
if ( V_1 -> V_28 == V_30 ) {
if ( F_4 ( V_1 -> V_12 , 294 , V_16 , V_2 ) == - 1 )
return - 1 ;
} else if ( V_1 -> V_28 == V_29 ) {
if ( F_4 ( V_1 -> V_12 , 297 , V_16 , V_2 ) == - 1 )
return - 1 ;
} else if ( V_1 -> V_28 == V_31 ) {
if ( F_4 ( V_1 -> V_12 , 504 , V_16 , V_2 ) == - 1 )
return - 1 ;
}
return 1 ;
V_26:
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
static T_4 V_20 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_5 * V_33 )
{
int V_34 ;
struct V_35 V_36 ;
T_6 V_37 , V_38 , V_39 ;
T_7 V_40 ;
int V_4 ;
struct V_41 V_41 ;
T_3 V_42 [ 8 ] ;
char V_43 [ 2 ] ;
* V_33 = F_6 ( V_1 -> V_12 ) ;
V_34 = F_7 ( V_1 -> V_12 , & V_36 , V_2 , V_3 ) ;
if ( V_34 <= 0 ) {
return FALSE ;
}
V_37 = F_8 ( & V_36 . V_37 ) ;
if ( V_37 == 0 ) {
* V_2 = 0 ;
return FALSE ;
}
V_39 = F_8 ( & V_36 . V_39 ) ;
V_38 = F_8 ( & V_36 . V_38 ) ;
if ( V_1 -> V_28 == V_29 ) {
V_39 -= 2 ;
V_38 -= 2 ;
}
V_1 -> V_42 . V_44 = V_45 | V_46 ;
V_1 -> V_42 . V_47 = V_38 ;
V_1 -> V_42 . V_48 = V_39 ;
V_41 . V_49 = F_8 ( & V_36 . V_50 . V_51 ) - 1900 ;
V_41 . V_52 = ( V_36 . V_50 . V_53 & 0x0f ) - 1 ;
V_41 . V_54 = V_36 . V_50 . V_55 ;
V_40 = F_9 ( & V_36 . V_50 . V_40 ) ;
V_41 . V_56 = V_40 / 3600 ;
V_41 . V_57 = ( V_40 % 3600 ) / 60 ;
V_41 . V_58 = V_40 % 60 ;
V_41 . V_59 = - 1 ;
V_1 -> V_42 . V_60 . V_61 = mktime ( & V_41 ) ;
V_1 -> V_42 . V_60 . V_62 = F_9 ( & V_36 . V_50 . V_63 ) * 1000 ;
switch ( V_1 -> V_28 ) {
case V_30 :
V_1 -> V_42 . V_64 . V_65 . V_66 = - 1 ;
break;
case V_29 :
V_1 -> V_42 . V_64 . V_67 . V_68 = ( V_36 . V_69 & 0x1 ) ?
0x00 : V_70 ;
break;
case V_31 :
if ( ! F_10 ( V_1 -> V_12 , V_42 , sizeof V_42 , V_2 ,
V_3 ) )
return FALSE ;
V_39 -= 8 ;
V_1 -> V_42 . V_47 -= 8 ;
V_1 -> V_42 . V_48 -= 8 ;
break;
}
F_11 ( V_1 -> V_71 , V_39 ) ;
if ( ! F_10 ( V_1 -> V_12 ,
F_12 ( V_1 -> V_71 ) , V_39 , V_2 , V_3 ) )
return FALSE ;
if ( V_1 -> V_28 == V_29 ) {
V_10 = V_11 ;
V_4 = F_2 ( & V_43 , sizeof V_43 , V_1 -> V_12 ) ;
if ( V_4 != sizeof V_43 ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_13 ;
return FALSE ;
}
}
return TRUE ;
}
static T_4
V_22 ( T_1 * V_1 , T_5 V_72 ,
struct V_73 * V_74 , T_3 * V_75 , int V_39 ,
int * V_2 , T_2 * * V_3 )
{
union V_76 * V_64 = & V_74 -> V_64 ;
int V_34 ;
struct V_35 V_36 ;
T_3 V_42 [ 8 ] ;
if ( F_4 ( V_1 -> V_77 , V_72 , V_78 , V_2 ) == - 1 )
return FALSE ;
V_34 = F_7 ( V_1 -> V_77 , & V_36 , V_2 , V_3 ) ;
if ( V_34 <= 0 ) {
if ( V_34 == 0 ) {
* V_2 = V_13 ;
}
return FALSE ;
}
switch ( V_1 -> V_28 ) {
case V_30 :
V_64 -> V_65 . V_66 = - 1 ;
break;
case V_29 :
V_64 -> V_67 . V_68 = ( V_36 . V_69 & 0x1 ) ? 0x00 : V_70 ;
break;
case V_31 :
if ( ! F_10 ( V_1 -> V_77 , V_42 , sizeof V_42 ,
V_2 , V_3 ) )
return FALSE ;
break;
}
return F_10 ( V_1 -> V_77 , V_75 , V_39 , V_2 , V_3 ) ;
}
static int
F_7 ( T_8 V_12 , struct V_35 * V_36 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_10 = V_11 ;
V_4 = F_2 ( V_36 , sizeof *V_36 , V_12 ) ;
if ( V_4 != sizeof *V_36 ) {
* V_2 = F_3 ( V_12 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
if ( V_4 != 0 ) {
* V_2 = V_13 ;
return - 1 ;
}
return 0 ;
}
return 1 ;
}
static T_4
F_10 ( T_8 V_12 , T_3 * V_75 , int V_39 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_10 = V_11 ;
V_4 = F_2 ( V_75 , V_39 , V_12 ) ;
if ( V_4 != V_39 ) {
* V_2 = F_3 ( V_12 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_13 ;
return FALSE ;
}
return TRUE ;
}
