void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , struct V_6 * V_7 , int V_8 )
{
unsigned char * V_9 = F_2 ( V_2 ) ;
memcpy ( & ( F_3 ( V_2 ) -> V_4 ) , V_4 , sizeof( struct V_3 ) ) ;
memcpy ( V_9 + sizeof( struct V_10 ) , V_4 -> V_11 , V_4 -> V_12 ) ;
V_4 = & ( F_3 ( V_2 ) -> V_4 ) ;
if ( V_4 -> V_13 )
memcpy ( V_9 + V_4 -> V_13 + V_9 [ V_4 -> V_13 + 1 ] - 4 , & V_5 , 4 ) ;
if ( ! V_8 ) {
if ( V_4 -> V_14 )
F_4 ( V_9 + V_4 -> V_15 + V_9 [ V_4 -> V_15 + 2 ] - 5 , V_2 , V_7 ) ;
if ( V_4 -> V_16 )
F_4 ( V_9 + V_4 -> V_17 + V_9 [ V_4 -> V_17 + 2 ] - 9 , V_2 , V_7 ) ;
if ( V_4 -> V_18 ) {
struct V_19 V_20 ;
T_1 V_21 ;
F_5 ( & V_20 ) ;
V_21 = F_6 ( ( V_20 . V_22 % 86400 ) * V_23 + V_20 . V_24 / V_25 ) ;
memcpy ( V_9 + V_4 -> V_17 + V_9 [ V_4 -> V_17 + 2 ] - 5 , & V_21 , 4 ) ;
}
return;
}
if ( V_4 -> V_15 ) {
memset ( V_9 + V_4 -> V_15 , V_26 , V_9 [ V_4 -> V_15 + 1 ] ) ;
V_4 -> V_15 = 0 ;
V_4 -> V_14 = 0 ;
}
if ( V_4 -> V_17 ) {
memset ( V_9 + V_4 -> V_17 , V_26 , V_9 [ V_4 -> V_17 + 1 ] ) ;
V_4 -> V_17 = 0 ;
V_4 -> V_16 = V_4 -> V_18 = 0 ;
}
}
int F_7 ( struct V_3 * V_27 , struct V_1 * V_2 )
{
const struct V_3 * V_28 ;
unsigned char * V_29 , * V_30 ;
int V_31 , V_32 ;
int V_12 ;
T_1 V_5 ;
memset ( V_27 , 0 , sizeof( struct V_3 ) ) ;
V_28 = & ( F_3 ( V_2 ) -> V_4 ) ;
if ( V_28 -> V_12 == 0 )
return 0 ;
V_29 = F_2 ( V_2 ) ;
V_30 = V_27 -> V_11 ;
V_5 = F_8 ( V_2 ) -> V_33 ;
if ( V_28 -> V_15 ) {
V_12 = V_29 [ V_28 -> V_15 + 1 ] ;
V_31 = V_29 [ V_28 -> V_15 + 2 ] ;
V_27 -> V_15 = V_27 -> V_12 + sizeof( struct V_10 ) ;
memcpy ( V_30 , V_29 + V_28 -> V_15 , V_12 ) ;
if ( V_28 -> V_14 && V_31 <= V_12 ) {
if ( V_31 + 3 > V_12 )
return - V_34 ;
V_30 [ 2 ] = V_31 + 4 ;
V_27 -> V_14 = 1 ;
}
V_30 += V_12 ;
V_27 -> V_12 += V_12 ;
}
if ( V_28 -> V_17 ) {
V_12 = V_29 [ V_28 -> V_17 + 1 ] ;
V_31 = V_29 [ V_28 -> V_17 + 2 ] ;
V_27 -> V_17 = V_27 -> V_12 + sizeof( struct V_10 ) ;
memcpy ( V_30 , V_29 + V_28 -> V_17 , V_12 ) ;
if ( V_31 <= V_12 ) {
if ( V_28 -> V_16 ) {
if ( V_31 + 3 > V_12 )
return - V_34 ;
V_27 -> V_16 = 1 ;
V_31 += 4 ;
}
if ( V_28 -> V_18 ) {
if ( V_31 + 3 > V_12 )
return - V_34 ;
if ( ( V_30 [ 3 ] & 0xF ) != V_35 ) {
V_27 -> V_18 = 1 ;
V_31 += 4 ;
} else {
V_27 -> V_18 = 0 ;
if ( V_31 + 7 <= V_12 ) {
T_1 V_36 ;
memcpy ( & V_36 , V_30 + V_31 - 1 , 4 ) ;
if ( F_9 ( F_10 ( F_11 ( V_2 ) -> V_37 ) , V_36 ) != V_38 ) {
V_27 -> V_18 = 1 ;
V_31 += 8 ;
}
}
}
}
V_30 [ 2 ] = V_31 ;
}
V_30 += V_12 ;
V_27 -> V_12 += V_12 ;
}
if ( V_28 -> V_13 ) {
unsigned char * V_39 = V_29 + V_28 -> V_13 ;
T_1 V_40 ;
V_12 = V_39 [ 1 ] ;
V_31 = V_39 [ 2 ] ;
V_32 = 0 ;
if ( V_31 > V_12 )
V_31 = V_12 + 1 ;
V_31 -= 4 ;
if ( V_31 > 3 ) {
memcpy ( & V_40 , & V_39 [ V_31 - 1 ] , 4 ) ;
for ( V_31 -= 4 , V_32 = 4 ; V_31 > 3 ; V_31 -= 4 , V_32 += 4 )
memcpy ( & V_30 [ V_32 - 1 ] , & V_39 [ V_31 - 1 ] , 4 ) ;
if ( memcmp ( & F_12 ( V_2 ) -> V_41 ,
& V_39 [ V_31 + 3 ] , 4 ) == 0 )
V_32 -= 4 ;
}
if ( V_32 > 3 ) {
memcpy ( & V_39 [ V_32 - 1 ] , & V_5 , 4 ) ;
V_27 -> V_40 = V_40 ;
V_30 [ 0 ] = V_39 [ 0 ] ;
V_30 [ 1 ] = V_32 + 3 ;
V_30 [ 2 ] = 4 ;
V_30 += V_32 + 3 ;
V_27 -> V_13 = V_27 -> V_12 + sizeof( struct V_10 ) ;
V_27 -> V_12 += V_32 + 3 ;
V_27 -> V_42 = V_28 -> V_42 ;
}
}
if ( V_28 -> V_43 ) {
V_12 = V_29 [ V_28 -> V_43 + 1 ] ;
V_27 -> V_43 = V_27 -> V_12 + sizeof( struct V_10 ) ;
memcpy ( V_30 , V_29 + V_28 -> V_43 , V_12 ) ;
V_30 += V_12 ;
V_27 -> V_12 += V_12 ;
}
while ( V_27 -> V_12 & 3 ) {
* V_30 ++ = V_44 ;
V_27 -> V_12 ++ ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
unsigned char * V_45 = F_2 ( V_2 ) + sizeof( struct V_10 ) ;
struct V_3 * V_4 = & ( F_3 ( V_2 ) -> V_4 ) ;
int V_46 = V_4 -> V_12 ;
int V_12 ;
while ( V_46 > 0 ) {
switch ( * V_45 ) {
case V_44 :
return;
case V_47 :
V_46 -- ;
V_45 ++ ;
continue;
}
V_12 = V_45 [ 1 ] ;
if ( V_12 < 2 || V_12 > V_46 )
return;
if ( ! F_14 ( * V_45 ) )
memset ( V_45 , V_47 , V_12 ) ;
V_46 -= V_12 ;
V_45 += V_12 ;
}
V_4 -> V_17 = 0 ;
V_4 -> V_15 = 0 ;
V_4 -> V_14 = 0 ;
V_4 -> V_16 = 0 ;
V_4 -> V_18 = 0 ;
}
int F_15 ( struct V_48 * V_48 ,
struct V_3 * V_4 , struct V_1 * V_2 )
{
int V_46 ;
unsigned char * V_9 ;
unsigned char * V_45 ;
int V_12 ;
unsigned char * V_49 = NULL ;
struct V_6 * V_7 = NULL ;
if ( V_2 != NULL ) {
V_7 = F_8 ( V_2 ) ;
V_45 = ( unsigned char * ) & ( F_12 ( V_2 ) [ 1 ] ) ;
} else
V_45 = V_4 -> V_11 ;
V_9 = V_45 - sizeof( struct V_10 ) ;
for ( V_46 = V_4 -> V_12 ; V_46 > 0 ; ) {
switch ( * V_45 ) {
case V_44 :
for ( V_45 ++ , V_46 -- ; V_46 > 0 ; V_45 ++ , V_46 -- ) {
if ( * V_45 != V_44 ) {
* V_45 = V_44 ;
V_4 -> V_50 = 1 ;
}
}
goto V_51;
case V_47 :
V_46 -- ;
V_45 ++ ;
continue;
}
V_12 = V_45 [ 1 ] ;
if ( V_12 < 2 || V_12 > V_46 ) {
V_49 = V_45 ;
goto error;
}
switch ( * V_45 ) {
case V_52 :
case V_53 :
if ( V_12 < 3 ) {
V_49 = V_45 + 1 ;
goto error;
}
if ( V_45 [ 2 ] < 4 ) {
V_49 = V_45 + 2 ;
goto error;
}
if ( V_4 -> V_13 ) {
V_49 = V_45 ;
goto error;
}
if ( ! V_2 ) {
if ( V_45 [ 2 ] != 4 || V_12 < 7 || ( ( V_12 - 3 ) & 3 ) ) {
V_49 = V_45 + 1 ;
goto error;
}
memcpy ( & V_4 -> V_40 , & V_45 [ 3 ] , 4 ) ;
if ( V_12 > 7 )
memmove ( & V_45 [ 3 ] , & V_45 [ 7 ] , V_12 - 7 ) ;
}
V_4 -> V_42 = ( V_45 [ 0 ] == V_52 ) ;
V_4 -> V_13 = V_45 - V_9 ;
break;
case V_54 :
if ( V_4 -> V_15 ) {
V_49 = V_45 ;
goto error;
}
if ( V_12 < 3 ) {
V_49 = V_45 + 1 ;
goto error;
}
if ( V_45 [ 2 ] < 4 ) {
V_49 = V_45 + 2 ;
goto error;
}
if ( V_45 [ 2 ] <= V_12 ) {
if ( V_45 [ 2 ] + 3 > V_12 ) {
V_49 = V_45 + 2 ;
goto error;
}
if ( V_7 ) {
memcpy ( & V_45 [ V_45 [ 2 ] - 1 ] , & V_7 -> V_33 , 4 ) ;
V_4 -> V_50 = 1 ;
}
V_45 [ 2 ] += 4 ;
V_4 -> V_14 = 1 ;
}
V_4 -> V_15 = V_45 - V_9 ;
break;
case V_55 :
if ( V_4 -> V_17 ) {
V_49 = V_45 ;
goto error;
}
if ( V_12 < 4 ) {
V_49 = V_45 + 1 ;
goto error;
}
if ( V_45 [ 2 ] < 5 ) {
V_49 = V_45 + 2 ;
goto error;
}
if ( V_45 [ 2 ] <= V_12 ) {
unsigned char * V_56 = NULL ;
if ( V_45 [ 2 ] + 3 > V_45 [ 1 ] ) {
V_49 = V_45 + 2 ;
goto error;
}
switch ( V_45 [ 3 ] & 0xF ) {
case V_57 :
V_4 -> V_17 = V_45 - V_9 ;
if ( V_2 )
V_56 = & V_45 [ V_45 [ 2 ] - 1 ] ;
V_4 -> V_18 = 1 ;
V_45 [ 2 ] += 4 ;
break;
case V_58 :
if ( V_45 [ 2 ] + 7 > V_45 [ 1 ] ) {
V_49 = V_45 + 2 ;
goto error;
}
V_4 -> V_17 = V_45 - V_9 ;
if ( V_7 ) {
memcpy ( & V_45 [ V_45 [ 2 ] - 1 ] , & V_7 -> V_33 , 4 ) ;
V_56 = & V_45 [ V_45 [ 2 ] + 3 ] ;
}
V_4 -> V_16 = 1 ;
V_4 -> V_18 = 1 ;
V_45 [ 2 ] += 8 ;
break;
case V_35 :
if ( V_45 [ 2 ] + 7 > V_45 [ 1 ] ) {
V_49 = V_45 + 2 ;
goto error;
}
V_4 -> V_17 = V_45 - V_9 ;
{
T_1 V_36 ;
memcpy ( & V_36 , & V_45 [ V_45 [ 2 ] - 1 ] , 4 ) ;
if ( F_9 ( V_48 , V_36 ) == V_38 )
break;
if ( V_2 )
V_56 = & V_45 [ V_45 [ 2 ] + 3 ] ;
}
V_4 -> V_18 = 1 ;
V_45 [ 2 ] += 8 ;
break;
default:
if ( ! V_2 && ! F_16 ( V_59 ) ) {
V_49 = V_45 + 3 ;
goto error;
}
break;
}
if ( V_56 ) {
struct V_19 V_20 ;
T_2 V_21 ;
F_5 ( & V_20 ) ;
V_21 = ( V_20 . V_22 % 86400 ) * V_23 + V_20 . V_24 / V_25 ;
F_17 ( V_21 , V_56 ) ;
V_4 -> V_50 = 1 ;
}
} else {
unsigned V_60 = V_45 [ 3 ] >> 4 ;
if ( V_60 == 15 ) {
V_49 = V_45 + 3 ;
goto error;
}
V_4 -> V_17 = V_45 - V_9 ;
if ( V_2 ) {
V_45 [ 3 ] = ( V_45 [ 3 ] & 0xF ) | ( ( V_60 + 1 ) << 4 ) ;
V_4 -> V_50 = 1 ;
}
}
break;
case V_61 :
if ( V_12 < 4 ) {
V_49 = V_45 + 1 ;
goto error;
}
if ( V_45 [ 2 ] == 0 && V_45 [ 3 ] == 0 )
V_4 -> V_62 = V_45 - V_9 ;
break;
case V_63 :
if ( ( ! V_2 && ! F_16 ( V_59 ) ) || V_4 -> V_43 ) {
V_49 = V_45 ;
goto error;
}
V_4 -> V_43 = V_45 - V_9 ;
if ( F_18 ( V_2 , & V_45 ) ) {
V_49 = V_45 ;
goto error;
}
break;
case V_64 :
case V_65 :
default:
if ( ! V_2 && ! F_16 ( V_59 ) ) {
V_49 = V_45 ;
goto error;
}
break;
}
V_46 -= V_12 ;
V_45 += V_12 ;
}
V_51:
if ( ! V_49 )
return 0 ;
error:
if ( V_2 ) {
F_19 ( V_2 , V_66 , 0 , F_6 ( ( V_49 - V_9 ) << 24 ) ) ;
}
return - V_34 ;
}
void F_20 ( struct V_3 * V_4 )
{
if ( V_4 -> V_13 ) {
unsigned char * V_45 = V_4 -> V_11 + V_4 -> V_13 - sizeof( struct V_10 ) ;
memmove ( V_45 + 7 , V_45 + 3 , V_45 [ 1 ] - 7 ) ;
memcpy ( V_45 + 3 , & V_4 -> V_40 , 4 ) ;
}
if ( V_4 -> V_14 ) {
unsigned char * V_45 = V_4 -> V_11 + V_4 -> V_15 - sizeof( struct V_10 ) ;
V_45 [ 2 ] -= 4 ;
memset ( & V_45 [ V_45 [ 2 ] - 1 ] , 0 , 4 ) ;
}
if ( V_4 -> V_17 ) {
unsigned char * V_45 = V_4 -> V_11 + V_4 -> V_17 - sizeof( struct V_10 ) ;
if ( V_4 -> V_18 ) {
V_45 [ 2 ] -= 4 ;
memset ( & V_45 [ V_45 [ 2 ] - 1 ] , 0 , 4 ) ;
if ( ( V_45 [ 3 ] & 0xF ) == V_35 )
V_45 [ 2 ] -= 4 ;
}
if ( V_4 -> V_16 ) {
V_45 [ 2 ] -= 4 ;
memset ( & V_45 [ V_45 [ 2 ] - 1 ] , 0 , 4 ) ;
}
}
}
static struct V_67 * F_21 ( const int V_12 )
{
return F_22 ( sizeof( struct V_67 ) + ( ( V_12 + 3 ) & ~ 3 ) ,
V_68 ) ;
}
static int F_23 ( struct V_48 * V_48 , struct V_67 * * V_69 ,
struct V_67 * V_4 , int V_12 )
{
while ( V_12 & 3 )
V_4 -> V_4 . V_11 [ V_12 ++ ] = V_44 ;
V_4 -> V_4 . V_12 = V_12 ;
if ( V_12 && F_15 ( V_48 , & V_4 -> V_4 , NULL ) ) {
F_24 ( V_4 ) ;
return - V_34 ;
}
F_24 ( * V_69 ) ;
* V_69 = V_4 ;
return 0 ;
}
int F_25 ( struct V_48 * V_48 , struct V_67 * * V_69 ,
unsigned char T_3 * V_70 , int V_12 )
{
struct V_67 * V_4 = F_21 ( V_12 ) ;
if ( ! V_4 )
return - V_71 ;
if ( V_12 && F_26 ( V_4 -> V_4 . V_11 , V_70 , V_12 ) ) {
F_24 ( V_4 ) ;
return - V_72 ;
}
return F_23 ( V_48 , V_69 , V_4 , V_12 ) ;
}
int F_27 ( struct V_48 * V_48 , struct V_67 * * V_69 ,
unsigned char * V_70 , int V_12 )
{
struct V_67 * V_4 = F_21 ( V_12 ) ;
if ( ! V_4 )
return - V_71 ;
if ( V_12 )
memcpy ( V_4 -> V_4 . V_11 , V_70 , V_12 ) ;
return F_23 ( V_48 , V_69 , V_4 , V_12 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & ( F_3 ( V_2 ) -> V_4 ) ;
unsigned char * V_45 ;
struct V_6 * V_7 = F_8 ( V_2 ) ;
unsigned char * V_73 = F_2 ( V_2 ) ;
if ( V_4 -> V_14 ) {
V_45 = ( unsigned char * ) V_73 + V_4 -> V_15 ;
F_4 ( & V_45 [ V_45 [ 2 ] - 5 ] , V_2 , V_7 ) ;
V_4 -> V_50 = 1 ;
}
if ( V_4 -> V_74 ) {
int V_75 , V_76 ;
V_45 = V_73 + V_4 -> V_13 ;
for ( V_75 = V_45 [ 2 ] , V_76 = V_45 [ 1 ] ;
V_75 <= V_76 ;
V_75 += 4
) {
if ( V_75 + 3 > V_76 )
break;
if ( memcmp ( & F_12 ( V_2 ) -> V_5 , & V_45 [ V_75 - 1 ] , 4 ) == 0 )
break;
}
if ( V_75 + 3 <= V_76 ) {
V_4 -> V_50 = 1 ;
F_4 ( & V_45 [ V_75 - 1 ] , V_2 , V_7 ) ;
V_45 [ 2 ] = V_75 + 4 ;
} else if ( F_29 () )
F_30 ( V_77 L_1 ) ;
if ( V_4 -> V_16 ) {
V_45 = V_73 + V_4 -> V_17 ;
F_4 ( & V_45 [ V_45 [ 2 ] - 9 ] , V_2 , V_7 ) ;
V_4 -> V_50 = 1 ;
}
}
if ( V_4 -> V_50 ) {
V_4 -> V_50 = 0 ;
F_31 ( F_12 ( V_2 ) ) ;
}
}
int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & ( F_3 ( V_2 ) -> V_4 ) ;
int V_76 , V_75 ;
T_1 V_78 ;
struct V_10 * V_9 = F_12 ( V_2 ) ;
unsigned char * V_45 = F_2 ( V_2 ) + V_4 -> V_13 ;
struct V_6 * V_7 = F_8 ( V_2 ) ;
struct V_6 * V_79 ;
unsigned long V_80 ;
int V_81 ;
if ( ! V_7 )
return 0 ;
if ( V_2 -> V_82 != V_83 )
return - V_34 ;
if ( V_7 -> V_84 == V_38 ) {
if ( ! V_4 -> V_42 )
return 0 ;
F_19 ( V_2 , V_66 , 0 , F_6 ( 16 << 24 ) ) ;
return - V_34 ;
}
if ( V_7 -> V_84 != V_85 )
return - V_34 ;
for ( V_75 = V_45 [ 2 ] , V_76 = V_45 [ 1 ] ; V_75 <= V_76 ; V_75 += 4 ) {
if ( V_75 + 3 > V_76 ) {
F_19 ( V_2 , V_66 , 0 , F_6 ( ( V_4 -> V_13 + 2 ) << 24 ) ) ;
return - V_34 ;
}
memcpy ( & V_78 , & V_45 [ V_75 - 1 ] , 4 ) ;
V_80 = V_2 -> V_86 ;
F_33 ( V_2 , NULL ) ;
V_81 = F_34 ( V_2 , V_78 , V_9 -> V_41 , V_9 -> V_87 , V_2 -> V_37 ) ;
V_79 = F_8 ( V_2 ) ;
if ( V_81 || ( V_79 -> V_84 != V_38 && V_79 -> V_84 != V_85 ) ) {
F_35 ( V_2 ) ;
V_2 -> V_86 = V_80 ;
return - V_34 ;
}
F_36 ( V_80 ) ;
if ( V_79 -> V_84 != V_85 )
break;
V_9 -> V_5 = V_78 ;
V_4 -> V_50 = 1 ;
}
if ( V_75 <= V_76 ) {
V_4 -> V_74 = 1 ;
V_4 -> V_50 = 1 ;
}
return 0 ;
}
