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
if ( V_10 == 8 ) {
F_5 ( V_3 , L_4 ,
V_11 [ 0 ] , V_11 [ 1 ] , V_11 [ 2 ] , V_11 [ 3 ] , V_11 [ 4 ] , V_11 [ 5 ] , V_11 [ 6 ] , V_11 [ 7 ] ) ;
} else if ( V_10 == 32 ) {
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ ) {
F_5 ( V_3 , L_5 , V_11 [ 0 ] << 8 | V_11 [ 1 ] ) ;
V_11 += 2 ;
if ( V_9 == 7 )
F_4 ( V_3 , L_6 ) ;
else if ( V_9 != 15 )
F_4 ( V_3 , L_7 ) ;
}
} else
F_5 ( V_3 , L_8 ) ;
return 1 ;
}
int F_6 ( T_5 * V_14 , T_3 * V_15 )
{
int V_16 , V_9 ;
T_6 * V_17 ;
V_17 = F_7 ( V_14 ) ;
if ( F_8 ( V_17 ) > 0 ) {
T_7 V_18 ;
V_18 . type = V_19 ;
V_18 . V_20 . V_21 = V_17 ;
V_16 = F_9 ( & V_18 , V_15 ) ;
if ( V_16 != V_22 )
return V_16 ;
V_18 . type = V_23 ;
for ( V_9 = - 1 ; ; ) {
const T_8 * V_24 ;
V_9 = F_10 ( V_17 , V_25 , V_9 ) ;
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
for ( V_9 = 0 ; V_9 < F_13 ( V_14 -> V_29 ) ; V_9 ++ ) {
T_7 * V_30 = F_14 ( V_14 -> V_29 , V_9 ) ;
V_16 = F_9 ( V_30 , V_15 ) ;
if ( V_16 != V_22 )
return V_16 ;
}
return V_22 ;
}
int F_15 ( T_5 * V_14 , T_3 * V_15 )
{
int V_16 , V_9 ;
T_6 * V_17 ;
T_9 V_31 ;
T_7 V_18 ;
V_31 . V_32 = 0 ;
V_31 . type = V_27 ;
V_18 . type = V_33 ;
V_18 . V_20 . V_34 = & V_31 ;
V_17 = F_7 ( V_14 ) ;
for ( V_9 = - 1 ; ; ) {
T_8 * V_24 ;
T_9 * V_35 ;
V_9 = F_10 ( V_17 , V_36 , V_9 ) ;
if ( V_9 == - 1 )
break;
V_24 = F_11 ( V_17 , V_9 ) ;
V_35 = F_12 ( V_24 ) ;
if ( F_16 ( V_35 ) ) {
unsigned char * V_37 ;
int V_38 = F_17 ( & V_37 , V_35 ) ;
if ( V_38 <= 0 )
return V_39 ;
V_31 . V_13 = V_38 ;
V_31 . V_12 = V_37 ;
V_16 = F_9 ( & V_18 , V_15 ) ;
F_18 ( V_37 ) ;
if ( V_16 != V_22 )
return V_16 ;
}
}
return V_22 ;
}
static int F_9 ( T_7 * V_30 , T_3 * V_15 )
{
T_10 * V_40 ;
int V_9 , V_16 , V_41 = 0 ;
for ( V_9 = 0 ; V_9 < F_19 ( V_15 -> V_6 ) ; V_9 ++ ) {
V_40 = F_20 ( V_15 -> V_6 , V_9 ) ;
if ( V_30 -> type != V_40 -> V_42 -> type )
continue;
if ( V_40 -> V_43 || V_40 -> V_44 )
return V_45 ;
if ( V_41 == 2 )
continue;
if ( V_41 == 0 )
V_41 = 1 ;
V_16 = F_21 ( V_30 , V_40 -> V_42 ) ;
if ( V_16 == V_22 )
V_41 = 2 ;
else if ( V_16 != V_46 )
return V_16 ;
}
if ( V_41 == 1 )
return V_46 ;
for ( V_9 = 0 ; V_9 < F_19 ( V_15 -> V_7 ) ; V_9 ++ ) {
V_40 = F_20 ( V_15 -> V_7 , V_9 ) ;
if ( V_30 -> type != V_40 -> V_42 -> type )
continue;
if ( V_40 -> V_43 || V_40 -> V_44 )
return V_45 ;
V_16 = F_21 ( V_30 , V_40 -> V_42 ) ;
if ( V_16 == V_22 )
return V_47 ;
else if ( V_16 != V_46 )
return V_16 ;
}
return V_22 ;
}
static int F_21 ( T_7 * V_30 , T_7 * V_42 )
{
switch ( V_42 -> type ) {
case V_19 :
return F_22 ( V_30 -> V_20 . V_21 , V_42 -> V_20 . V_21 ) ;
case V_33 :
return F_23 ( V_30 -> V_20 . V_34 , V_42 -> V_20 . V_34 ) ;
case V_23 :
return F_24 ( V_30 -> V_20 . V_26 , V_42 -> V_20 . V_26 ) ;
case V_48 :
return F_25 ( V_30 -> V_20 . V_49 ,
V_42 -> V_20 . V_49 ) ;
case V_50 :
return F_26 ( V_30 -> V_20 . V_51 , V_42 -> V_20 . V_51 ) ;
default:
return V_52 ;
}
}
static int F_22 ( T_6 * V_17 , T_6 * V_42 )
{
if ( V_17 -> V_53 && F_27 ( V_17 , NULL ) < 0 )
return V_39 ;
if ( V_42 -> V_53 && F_27 ( V_42 , NULL ) < 0 )
return V_39 ;
if ( V_42 -> V_54 > V_17 -> V_54 )
return V_46 ;
if ( memcmp ( V_42 -> V_55 , V_17 -> V_55 , V_42 -> V_54 ) )
return V_46 ;
return V_22 ;
}
static int F_23 ( T_11 * V_56 , T_11 * V_42 )
{
char * V_57 = ( char * ) V_42 -> V_12 ;
char * V_58 = ( char * ) V_56 -> V_12 ;
if ( ! * V_57 )
return V_22 ;
if ( V_56 -> V_13 > V_42 -> V_13 ) {
V_58 += V_56 -> V_13 - V_42 -> V_13 ;
if ( * V_57 != '.' && V_58 [ - 1 ] != '.' )
return V_46 ;
}
if ( strcasecmp ( V_57 , V_58 ) )
return V_46 ;
return V_22 ;
}
static int F_24 ( T_11 * V_59 , T_11 * V_42 )
{
const char * V_57 = ( char * ) V_42 -> V_12 ;
const char * V_60 = ( char * ) V_59 -> V_12 ;
const char * V_61 = strchr ( V_57 , '@' ) ;
const char * V_62 = strchr ( V_60 , '@' ) ;
if ( ! V_62 )
return V_28 ;
if ( ! V_61 && ( * V_57 == '.' ) ) {
if ( V_59 -> V_13 > V_42 -> V_13 ) {
V_60 += V_59 -> V_13 - V_42 -> V_13 ;
if ( strcasecmp ( V_57 , V_60 ) == 0 )
return V_22 ;
}
return V_46 ;
}
if ( V_61 ) {
if ( V_61 != V_57 ) {
if ( ( V_61 - V_57 ) != ( V_62 - V_60 ) )
return V_46 ;
if ( strncmp ( V_57 , V_60 , V_62 - V_60 ) )
return V_46 ;
}
V_57 = V_61 + 1 ;
}
V_60 = V_62 + 1 ;
if ( strcasecmp ( V_57 , V_60 ) )
return V_46 ;
return V_22 ;
}
static int F_25 ( T_11 * V_63 , T_11 * V_42 )
{
const char * V_57 = ( char * ) V_42 -> V_12 ;
const char * V_64 = ( char * ) V_63 -> V_12 ;
const char * V_11 = strchr ( V_64 , ':' ) ;
int V_65 ;
if ( ! V_11 || ( V_11 [ 1 ] != '/' ) || ( V_11 [ 2 ] != '/' ) )
return V_28 ;
V_64 = V_11 + 3 ;
V_11 = strchr ( V_64 , ':' ) ;
if ( ! V_11 )
V_11 = strchr ( V_64 , '/' ) ;
if ( ! V_11 )
V_65 = strlen ( V_64 ) ;
else
V_65 = V_11 - V_64 ;
if ( V_65 == 0 )
return V_28 ;
if ( * V_57 == '.' ) {
if ( V_65 > V_42 -> V_13 ) {
V_11 = V_64 + V_65 - V_42 -> V_13 ;
if ( strncasecmp ( V_11 , V_57 , V_42 -> V_13 ) == 0 )
return V_22 ;
}
return V_46 ;
}
if ( ( V_42 -> V_13 != ( int ) V_65 )
|| strncasecmp ( V_64 , V_57 , V_65 ) )
return V_46 ;
return V_22 ;
}
static int F_26 ( T_4 * V_8 , T_4 * V_42 )
{
int V_65 , V_66 , V_9 ;
unsigned char * V_64 , * V_57 , * V_67 ;
V_64 = V_8 -> V_12 ;
V_65 = V_8 -> V_13 ;
V_57 = V_42 -> V_12 ;
V_66 = V_42 -> V_13 ;
if ( ! ( ( V_65 == 4 ) || ( V_65 == 16 ) ) )
return V_28 ;
if ( ! ( ( V_66 == 8 ) || ( V_66 == 32 ) ) )
return V_28 ;
if ( V_65 * 2 != V_66 )
return V_46 ;
V_67 = V_42 -> V_12 + V_65 ;
for ( V_9 = 0 ; V_9 < V_65 ; V_9 ++ )
if ( ( V_64 [ V_9 ] & V_67 [ V_9 ] ) != ( V_57 [ V_9 ] & V_67 [ V_9 ] ) )
return V_46 ;
return V_22 ;
}
