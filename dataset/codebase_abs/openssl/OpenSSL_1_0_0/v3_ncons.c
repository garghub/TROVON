int F_1 ( const T_1 * V_1 , void * V_2 ,
T_2 * V_3 , int V_4 )
{
T_3 * V_5 = V_2 ;
F_2 ( V_1 , V_5 -> V_6 ,
V_3 , V_4 , L_1 ) ;
F_2 ( V_1 , V_5 -> V_7 ,
V_3 , V_4 , L_2 ) ;
return 1 ;
}
static int F_3 ( T_2 * V_3 , T_4 * V_8 )
{
int V_9 , V_10 ;
unsigned char * V_11 ;
V_11 = V_8 -> V_12 ;
V_10 = V_8 -> V_13 ;
F_4 ( V_3 , L_3 ) ;
if( V_10 == 8 )
{
F_5 ( V_3 , L_4 ,
V_11 [ 0 ] , V_11 [ 1 ] , V_11 [ 2 ] , V_11 [ 3 ] ,
V_11 [ 4 ] , V_11 [ 5 ] , V_11 [ 6 ] , V_11 [ 7 ] ) ;
}
else if( V_10 == 32 )
{
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ )
{
F_5 ( V_3 , L_5 , V_11 [ 0 ] << 8 | V_11 [ 1 ] ) ;
V_11 += 2 ;
if ( V_9 == 7 )
F_4 ( V_3 , L_6 ) ;
else if ( V_9 != 15 )
F_4 ( V_3 , L_7 ) ;
}
}
else
F_5 ( V_3 , L_8 ) ;
return 1 ;
}
int F_6 ( T_5 * V_14 , T_3 * V_15 )
{
int V_16 , V_9 ;
T_6 * V_17 ;
V_17 = F_7 ( V_14 ) ;
if ( F_8 ( V_17 ) > 0 )
{
T_7 V_18 ;
V_18 . type = V_19 ;
V_18 . V_20 . V_21 = V_17 ;
V_16 = F_9 ( & V_18 , V_15 ) ;
if ( V_16 != V_22 )
return V_16 ;
V_18 . type = V_23 ;
for ( V_9 = - 1 ; ; )
{
T_8 * V_24 ;
V_9 = F_10 ( V_17 ,
V_25 ,
V_9 ) ;
if ( V_9 == - 1 )
break;
V_24 = F_11 ( V_17 , V_9 ) ;
V_18 . V_20 . V_26 = F_12 ( V_24 ) ;
if ( V_18 . V_20 . V_26 -> type != V_27 )
return V_28 ;
V_16 = F_9 ( & V_18 , V_15 ) ;
if ( V_16 != V_22 )
return V_16 ;
}
}
for ( V_9 = 0 ; V_9 < F_13 ( V_14 -> V_29 ) ; V_9 ++ )
{
T_7 * V_30 = F_14 ( V_14 -> V_29 , V_9 ) ;
V_16 = F_9 ( V_30 , V_15 ) ;
if ( V_16 != V_22 )
return V_16 ;
}
return V_22 ;
}
static int F_9 ( T_7 * V_30 , T_3 * V_15 )
{
T_9 * V_31 ;
int V_9 , V_16 , V_32 = 0 ;
for ( V_9 = 0 ; V_9 < F_15 ( V_15 -> V_6 ) ; V_9 ++ )
{
V_31 = F_16 ( V_15 -> V_6 , V_9 ) ;
if ( V_30 -> type != V_31 -> V_33 -> type )
continue;
if ( V_31 -> V_34 || V_31 -> V_35 )
return V_36 ;
if ( V_32 == 2 )
continue;
if ( V_32 == 0 )
V_32 = 1 ;
V_16 = F_17 ( V_30 , V_31 -> V_33 ) ;
if ( V_16 == V_22 )
V_32 = 2 ;
else if ( V_16 != V_37 )
return V_16 ;
}
if ( V_32 == 1 )
return V_37 ;
for ( V_9 = 0 ; V_9 < F_15 ( V_15 -> V_7 ) ; V_9 ++ )
{
V_31 = F_16 ( V_15 -> V_7 , V_9 ) ;
if ( V_30 -> type != V_31 -> V_33 -> type )
continue;
if ( V_31 -> V_34 || V_31 -> V_35 )
return V_36 ;
V_16 = F_17 ( V_30 , V_31 -> V_33 ) ;
if ( V_16 == V_22 )
return V_38 ;
else if ( V_16 != V_37 )
return V_16 ;
}
return V_22 ;
}
static int F_17 ( T_7 * V_30 , T_7 * V_33 )
{
switch( V_33 -> type )
{
case V_19 :
return F_18 ( V_30 -> V_20 . V_21 , V_33 -> V_20 . V_21 ) ;
case V_39 :
return F_19 ( V_30 -> V_20 . V_40 , V_33 -> V_20 . V_40 ) ;
case V_23 :
return F_20 ( V_30 -> V_20 . V_26 , V_33 -> V_20 . V_26 ) ;
case V_41 :
return F_21 ( V_30 -> V_20 . V_42 ,
V_33 -> V_20 . V_42 ) ;
default:
return V_43 ;
}
}
static int F_18 ( T_6 * V_17 , T_6 * V_33 )
{
if ( V_17 -> V_44 && F_22 ( V_17 , NULL ) < 0 )
return V_45 ;
if ( V_33 -> V_44 && F_22 ( V_33 , NULL ) < 0 )
return V_45 ;
if ( V_33 -> V_46 > V_17 -> V_46 )
return V_37 ;
if ( memcmp ( V_33 -> V_47 , V_17 -> V_47 , V_33 -> V_46 ) )
return V_37 ;
return V_22 ;
}
static int F_19 ( T_10 * V_48 , T_10 * V_33 )
{
char * V_49 = ( char * ) V_33 -> V_12 ;
char * V_50 = ( char * ) V_48 -> V_12 ;
if ( ! * V_49 )
return V_22 ;
if ( V_48 -> V_13 > V_33 -> V_13 )
{
V_50 += V_48 -> V_13 - V_33 -> V_13 ;
if ( V_50 [ - 1 ] != '.' )
return V_37 ;
}
if ( strcasecmp ( V_49 , V_50 ) )
return V_37 ;
return V_22 ;
}
static int F_20 ( T_10 * V_51 , T_10 * V_33 )
{
const char * V_49 = ( char * ) V_33 -> V_12 ;
const char * V_52 = ( char * ) V_51 -> V_12 ;
const char * V_53 = strchr ( V_49 , '@' ) ;
const char * V_54 = strchr ( V_52 , '@' ) ;
if ( ! V_54 )
return V_28 ;
if ( ! V_53 && ( * V_49 == '.' ) )
{
if ( V_51 -> V_13 > V_33 -> V_13 )
{
V_52 += V_51 -> V_13 - V_33 -> V_13 ;
if ( ! strcasecmp ( V_49 , V_52 ) )
return V_22 ;
}
return V_37 ;
}
if ( V_53 )
{
if ( V_53 != V_49 )
{
if ( ( V_53 - V_49 ) != ( V_54 - V_52 ) )
return V_37 ;
if ( strncmp ( V_49 , V_52 , V_54 - V_52 ) )
return V_37 ;
}
V_49 = V_53 + 1 ;
}
V_52 = V_54 + 1 ;
if ( strcasecmp ( V_49 , V_52 ) )
return V_37 ;
return V_22 ;
}
static int F_21 ( T_10 * V_55 , T_10 * V_33 )
{
const char * V_49 = ( char * ) V_33 -> V_12 ;
const char * V_56 = ( char * ) V_55 -> V_12 ;
const char * V_11 = strchr ( V_56 , ':' ) ;
int V_57 ;
if ( ! V_11 || ( V_11 [ 1 ] != '/' ) || ( V_11 [ 2 ] != '/' ) )
return V_28 ;
V_56 = V_11 + 3 ;
V_11 = strchr ( V_56 , ':' ) ;
if ( ! V_11 )
V_11 = strchr ( V_56 , '/' ) ;
if ( ! V_11 )
V_57 = strlen ( V_56 ) ;
else
V_57 = V_11 - V_56 ;
if ( V_57 == 0 )
return V_28 ;
if ( * V_49 == '.' )
{
if ( V_57 > V_33 -> V_13 )
{
V_11 = V_56 + V_57 - V_33 -> V_13 ;
if ( ! strncasecmp ( V_11 , V_49 , V_33 -> V_13 ) )
return V_22 ;
}
return V_37 ;
}
if ( ( V_33 -> V_13 != ( int ) V_57 ) || strncasecmp ( V_56 , V_49 , V_57 ) )
return V_37 ;
return V_22 ;
}
