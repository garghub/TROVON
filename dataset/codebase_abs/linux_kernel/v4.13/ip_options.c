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
T_1 V_19 ;
V_19 = F_5 () ;
memcpy ( V_9 + V_4 -> V_17 + V_9 [ V_4 -> V_17 + 2 ] - 5 , & V_19 , 4 ) ;
}
return;
}
if ( V_4 -> V_15 ) {
memset ( V_9 + V_4 -> V_15 , V_20 , V_9 [ V_4 -> V_15 + 1 ] ) ;
V_4 -> V_15 = 0 ;
V_4 -> V_14 = 0 ;
}
if ( V_4 -> V_17 ) {
memset ( V_9 + V_4 -> V_17 , V_20 , V_9 [ V_4 -> V_17 + 1 ] ) ;
V_4 -> V_17 = 0 ;
V_4 -> V_16 = V_4 -> V_18 = 0 ;
}
}
int F_6 ( struct V_3 * V_21 , struct V_1 * V_2 ,
const struct V_3 * V_22 )
{
unsigned char * V_23 , * V_24 ;
int V_25 , V_26 ;
int V_12 ;
memset ( V_21 , 0 , sizeof( struct V_3 ) ) ;
if ( V_22 -> V_12 == 0 )
return 0 ;
V_23 = F_2 ( V_2 ) ;
V_24 = V_21 -> V_11 ;
if ( V_22 -> V_15 ) {
V_12 = V_23 [ V_22 -> V_15 + 1 ] ;
V_25 = V_23 [ V_22 -> V_15 + 2 ] ;
V_21 -> V_15 = V_21 -> V_12 + sizeof( struct V_10 ) ;
memcpy ( V_24 , V_23 + V_22 -> V_15 , V_12 ) ;
if ( V_22 -> V_14 && V_25 <= V_12 ) {
if ( V_25 + 3 > V_12 )
return - V_27 ;
V_24 [ 2 ] = V_25 + 4 ;
V_21 -> V_14 = 1 ;
}
V_24 += V_12 ;
V_21 -> V_12 += V_12 ;
}
if ( V_22 -> V_17 ) {
V_12 = V_23 [ V_22 -> V_17 + 1 ] ;
V_25 = V_23 [ V_22 -> V_17 + 2 ] ;
V_21 -> V_17 = V_21 -> V_12 + sizeof( struct V_10 ) ;
memcpy ( V_24 , V_23 + V_22 -> V_17 , V_12 ) ;
if ( V_25 <= V_12 ) {
if ( V_22 -> V_16 ) {
if ( V_25 + 3 > V_12 )
return - V_27 ;
V_21 -> V_16 = 1 ;
V_25 += 4 ;
}
if ( V_22 -> V_18 ) {
if ( V_25 + 3 > V_12 )
return - V_27 ;
if ( ( V_24 [ 3 ] & 0xF ) != V_28 ) {
V_21 -> V_18 = 1 ;
V_25 += 4 ;
} else {
V_21 -> V_18 = 0 ;
if ( V_25 + 7 <= V_12 ) {
T_1 V_29 ;
memcpy ( & V_29 , V_24 + V_25 - 1 , 4 ) ;
if ( F_7 ( F_8 ( F_9 ( V_2 ) -> V_30 ) , V_29 ) != V_31 ) {
V_21 -> V_18 = 1 ;
V_25 += 8 ;
}
}
}
}
V_24 [ 2 ] = V_25 ;
}
V_24 += V_12 ;
V_21 -> V_12 += V_12 ;
}
if ( V_22 -> V_13 ) {
unsigned char * V_32 = V_23 + V_22 -> V_13 ;
T_1 V_33 ;
V_12 = V_32 [ 1 ] ;
V_25 = V_32 [ 2 ] ;
V_26 = 0 ;
if ( V_25 > V_12 )
V_25 = V_12 + 1 ;
V_25 -= 4 ;
if ( V_25 > 3 ) {
memcpy ( & V_33 , & V_32 [ V_25 - 1 ] , 4 ) ;
for ( V_25 -= 4 , V_26 = 4 ; V_25 > 3 ; V_25 -= 4 , V_26 += 4 )
memcpy ( & V_24 [ V_26 - 1 ] , & V_32 [ V_25 - 1 ] , 4 ) ;
if ( memcmp ( & F_10 ( V_2 ) -> V_34 ,
& V_32 [ V_25 + 3 ] , 4 ) == 0 )
V_26 -= 4 ;
}
if ( V_26 > 3 ) {
T_1 V_5 = F_11 ( V_2 ) ;
memcpy ( & V_32 [ V_26 - 1 ] , & V_5 , 4 ) ;
V_21 -> V_33 = V_33 ;
V_24 [ 0 ] = V_32 [ 0 ] ;
V_24 [ 1 ] = V_26 + 3 ;
V_24 [ 2 ] = 4 ;
V_24 += V_26 + 3 ;
V_21 -> V_13 = V_21 -> V_12 + sizeof( struct V_10 ) ;
V_21 -> V_12 += V_26 + 3 ;
V_21 -> V_35 = V_22 -> V_35 ;
}
}
if ( V_22 -> V_36 ) {
V_12 = V_23 [ V_22 -> V_36 + 1 ] ;
V_21 -> V_36 = V_21 -> V_12 + sizeof( struct V_10 ) ;
memcpy ( V_24 , V_23 + V_22 -> V_36 , V_12 ) ;
V_24 += V_12 ;
V_21 -> V_12 += V_12 ;
}
while ( V_21 -> V_12 & 3 ) {
* V_24 ++ = V_37 ;
V_21 -> V_12 ++ ;
}
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
unsigned char * V_38 = F_2 ( V_2 ) + sizeof( struct V_10 ) ;
struct V_3 * V_4 = & ( F_3 ( V_2 ) -> V_4 ) ;
int V_39 = V_4 -> V_12 ;
int V_12 ;
while ( V_39 > 0 ) {
switch ( * V_38 ) {
case V_37 :
return;
case V_40 :
V_39 -- ;
V_38 ++ ;
continue;
}
V_12 = V_38 [ 1 ] ;
if ( V_12 < 2 || V_12 > V_39 )
return;
if ( ! F_13 ( * V_38 ) )
memset ( V_38 , V_40 , V_12 ) ;
V_39 -= V_12 ;
V_38 += V_12 ;
}
V_4 -> V_17 = 0 ;
V_4 -> V_15 = 0 ;
V_4 -> V_14 = 0 ;
V_4 -> V_16 = 0 ;
V_4 -> V_18 = 0 ;
}
static void F_14 ( T_1 * V_41 , struct V_1 * V_2 )
{
if ( * V_41 == F_15 ( V_42 ) )
* V_41 = F_11 ( V_2 ) ;
}
int F_16 ( struct V_43 * V_43 ,
struct V_3 * V_4 , struct V_1 * V_2 )
{
T_1 V_41 = F_15 ( V_42 ) ;
unsigned char * V_44 = NULL ;
struct V_6 * V_7 = NULL ;
unsigned char * V_38 ;
unsigned char * V_9 ;
int V_12 , V_39 ;
if ( V_2 ) {
V_7 = F_17 ( V_2 ) ;
V_38 = ( unsigned char * ) & ( F_10 ( V_2 ) [ 1 ] ) ;
} else
V_38 = V_4 -> V_11 ;
V_9 = V_38 - sizeof( struct V_10 ) ;
for ( V_39 = V_4 -> V_12 ; V_39 > 0 ; ) {
switch ( * V_38 ) {
case V_37 :
for ( V_38 ++ , V_39 -- ; V_39 > 0 ; V_38 ++ , V_39 -- ) {
if ( * V_38 != V_37 ) {
* V_38 = V_37 ;
V_4 -> V_45 = 1 ;
}
}
goto V_46;
case V_40 :
V_39 -- ;
V_38 ++ ;
continue;
}
if ( F_18 ( V_39 < 2 ) ) {
V_44 = V_38 ;
goto error;
}
V_12 = V_38 [ 1 ] ;
if ( V_12 < 2 || V_12 > V_39 ) {
V_44 = V_38 ;
goto error;
}
switch ( * V_38 ) {
case V_47 :
case V_48 :
if ( V_12 < 3 ) {
V_44 = V_38 + 1 ;
goto error;
}
if ( V_38 [ 2 ] < 4 ) {
V_44 = V_38 + 2 ;
goto error;
}
if ( V_4 -> V_13 ) {
V_44 = V_38 ;
goto error;
}
if ( ! V_2 ) {
if ( V_38 [ 2 ] != 4 || V_12 < 7 || ( ( V_12 - 3 ) & 3 ) ) {
V_44 = V_38 + 1 ;
goto error;
}
memcpy ( & V_4 -> V_33 , & V_38 [ 3 ] , 4 ) ;
if ( V_12 > 7 )
memmove ( & V_38 [ 3 ] , & V_38 [ 7 ] , V_12 - 7 ) ;
}
V_4 -> V_35 = ( V_38 [ 0 ] == V_47 ) ;
V_4 -> V_13 = V_38 - V_9 ;
break;
case V_49 :
if ( V_4 -> V_15 ) {
V_44 = V_38 ;
goto error;
}
if ( V_12 < 3 ) {
V_44 = V_38 + 1 ;
goto error;
}
if ( V_38 [ 2 ] < 4 ) {
V_44 = V_38 + 2 ;
goto error;
}
if ( V_38 [ 2 ] <= V_12 ) {
if ( V_38 [ 2 ] + 3 > V_12 ) {
V_44 = V_38 + 2 ;
goto error;
}
if ( V_7 ) {
F_14 ( & V_41 , V_2 ) ;
memcpy ( & V_38 [ V_38 [ 2 ] - 1 ] , & V_41 , 4 ) ;
V_4 -> V_45 = 1 ;
}
V_38 [ 2 ] += 4 ;
V_4 -> V_14 = 1 ;
}
V_4 -> V_15 = V_38 - V_9 ;
break;
case V_50 :
if ( V_4 -> V_17 ) {
V_44 = V_38 ;
goto error;
}
if ( V_12 < 4 ) {
V_44 = V_38 + 1 ;
goto error;
}
if ( V_38 [ 2 ] < 5 ) {
V_44 = V_38 + 2 ;
goto error;
}
if ( V_38 [ 2 ] <= V_12 ) {
unsigned char * V_51 = NULL ;
if ( V_38 [ 2 ] + 3 > V_12 ) {
V_44 = V_38 + 2 ;
goto error;
}
switch ( V_38 [ 3 ] & 0xF ) {
case V_52 :
if ( V_2 )
V_51 = & V_38 [ V_38 [ 2 ] - 1 ] ;
V_4 -> V_18 = 1 ;
V_38 [ 2 ] += 4 ;
break;
case V_53 :
if ( V_38 [ 2 ] + 7 > V_12 ) {
V_44 = V_38 + 2 ;
goto error;
}
if ( V_7 ) {
F_14 ( & V_41 , V_2 ) ;
memcpy ( & V_38 [ V_38 [ 2 ] - 1 ] , & V_41 , 4 ) ;
V_51 = & V_38 [ V_38 [ 2 ] + 3 ] ;
}
V_4 -> V_16 = 1 ;
V_4 -> V_18 = 1 ;
V_38 [ 2 ] += 8 ;
break;
case V_28 :
if ( V_38 [ 2 ] + 7 > V_12 ) {
V_44 = V_38 + 2 ;
goto error;
}
{
T_1 V_29 ;
memcpy ( & V_29 , & V_38 [ V_38 [ 2 ] - 1 ] , 4 ) ;
if ( F_7 ( V_43 , V_29 ) == V_31 )
break;
if ( V_2 )
V_51 = & V_38 [ V_38 [ 2 ] + 3 ] ;
}
V_4 -> V_18 = 1 ;
V_38 [ 2 ] += 8 ;
break;
default:
if ( ! V_2 && ! F_19 ( V_43 -> V_54 , V_55 ) ) {
V_44 = V_38 + 3 ;
goto error;
}
break;
}
if ( V_51 ) {
T_1 V_19 ;
V_19 = F_5 () ;
memcpy ( V_51 , & V_19 , 4 ) ;
V_4 -> V_45 = 1 ;
}
} else if ( ( V_38 [ 3 ] & 0xF ) != V_28 ) {
unsigned int V_56 = V_38 [ 3 ] >> 4 ;
if ( V_56 == 15 ) {
V_44 = V_38 + 3 ;
goto error;
}
if ( V_2 ) {
V_38 [ 3 ] = ( V_38 [ 3 ] & 0xF ) | ( ( V_56 + 1 ) << 4 ) ;
V_4 -> V_45 = 1 ;
}
}
V_4 -> V_17 = V_38 - V_9 ;
break;
case V_57 :
if ( V_12 < 4 ) {
V_44 = V_38 + 1 ;
goto error;
}
if ( V_38 [ 2 ] == 0 && V_38 [ 3 ] == 0 )
V_4 -> V_58 = V_38 - V_9 ;
break;
case V_59 :
if ( ( ! V_2 && ! F_19 ( V_43 -> V_54 , V_55 ) ) || V_4 -> V_36 ) {
V_44 = V_38 ;
goto error;
}
V_4 -> V_36 = V_38 - V_9 ;
if ( F_20 ( V_2 , & V_38 ) ) {
V_44 = V_38 ;
goto error;
}
break;
case V_60 :
case V_61 :
default:
if ( ! V_2 && ! F_19 ( V_43 -> V_54 , V_55 ) ) {
V_44 = V_38 ;
goto error;
}
break;
}
V_39 -= V_12 ;
V_38 += V_12 ;
}
V_46:
if ( ! V_44 )
return 0 ;
error:
if ( V_2 ) {
F_21 ( V_2 , V_62 , 0 , F_15 ( ( V_44 - V_9 ) << 24 ) ) ;
}
return - V_27 ;
}
void F_22 ( struct V_3 * V_4 )
{
if ( V_4 -> V_13 ) {
unsigned char * V_38 = V_4 -> V_11 + V_4 -> V_13 - sizeof( struct V_10 ) ;
memmove ( V_38 + 7 , V_38 + 3 , V_38 [ 1 ] - 7 ) ;
memcpy ( V_38 + 3 , & V_4 -> V_33 , 4 ) ;
}
if ( V_4 -> V_14 ) {
unsigned char * V_38 = V_4 -> V_11 + V_4 -> V_15 - sizeof( struct V_10 ) ;
V_38 [ 2 ] -= 4 ;
memset ( & V_38 [ V_38 [ 2 ] - 1 ] , 0 , 4 ) ;
}
if ( V_4 -> V_17 ) {
unsigned char * V_38 = V_4 -> V_11 + V_4 -> V_17 - sizeof( struct V_10 ) ;
if ( V_4 -> V_18 ) {
V_38 [ 2 ] -= 4 ;
memset ( & V_38 [ V_38 [ 2 ] - 1 ] , 0 , 4 ) ;
if ( ( V_38 [ 3 ] & 0xF ) == V_28 )
V_38 [ 2 ] -= 4 ;
}
if ( V_4 -> V_16 ) {
V_38 [ 2 ] -= 4 ;
memset ( & V_38 [ V_38 [ 2 ] - 1 ] , 0 , 4 ) ;
}
}
}
static struct V_63 * F_23 ( const int V_12 )
{
return F_24 ( sizeof( struct V_63 ) + ( ( V_12 + 3 ) & ~ 3 ) ,
V_64 ) ;
}
static int F_25 ( struct V_43 * V_43 , struct V_63 * * V_65 ,
struct V_63 * V_4 , int V_12 )
{
while ( V_12 & 3 )
V_4 -> V_4 . V_11 [ V_12 ++ ] = V_37 ;
V_4 -> V_4 . V_12 = V_12 ;
if ( V_12 && F_16 ( V_43 , & V_4 -> V_4 , NULL ) ) {
F_26 ( V_4 ) ;
return - V_27 ;
}
F_26 ( * V_65 ) ;
* V_65 = V_4 ;
return 0 ;
}
int F_27 ( struct V_43 * V_43 , struct V_63 * * V_65 ,
unsigned char T_2 * V_66 , int V_12 )
{
struct V_63 * V_4 = F_23 ( V_12 ) ;
if ( ! V_4 )
return - V_67 ;
if ( V_12 && F_28 ( V_4 -> V_4 . V_11 , V_66 , V_12 ) ) {
F_26 ( V_4 ) ;
return - V_68 ;
}
return F_25 ( V_43 , V_65 , V_4 , V_12 ) ;
}
int F_29 ( struct V_43 * V_43 , struct V_63 * * V_65 ,
unsigned char * V_66 , int V_12 )
{
struct V_63 * V_4 = F_23 ( V_12 ) ;
if ( ! V_4 )
return - V_67 ;
if ( V_12 )
memcpy ( V_4 -> V_4 . V_11 , V_66 , V_12 ) ;
return F_25 ( V_43 , V_65 , V_4 , V_12 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & ( F_3 ( V_2 ) -> V_4 ) ;
unsigned char * V_38 ;
struct V_6 * V_7 = F_17 ( V_2 ) ;
unsigned char * V_69 = F_2 ( V_2 ) ;
if ( V_4 -> V_14 ) {
V_38 = ( unsigned char * ) V_69 + V_4 -> V_15 ;
F_4 ( & V_38 [ V_38 [ 2 ] - 5 ] , V_2 , V_7 ) ;
V_4 -> V_45 = 1 ;
}
if ( V_4 -> V_70 ) {
int V_71 , V_72 ;
V_38 = V_69 + V_4 -> V_13 ;
for ( V_71 = V_38 [ 2 ] , V_72 = V_38 [ 1 ] ;
V_71 <= V_72 ;
V_71 += 4
) {
if ( V_71 + 3 > V_72 )
break;
if ( memcmp ( & V_4 -> V_73 , & V_38 [ V_71 - 1 ] , 4 ) == 0 )
break;
}
if ( V_71 + 3 <= V_72 ) {
V_4 -> V_45 = 1 ;
F_10 ( V_2 ) -> V_5 = V_4 -> V_73 ;
F_4 ( & V_38 [ V_71 - 1 ] , V_2 , V_7 ) ;
V_38 [ 2 ] = V_71 + 4 ;
} else {
F_31 ( L_1 ,
V_74 ) ;
}
if ( V_4 -> V_16 ) {
V_38 = V_69 + V_4 -> V_17 ;
F_4 ( & V_38 [ V_38 [ 2 ] - 9 ] , V_2 , V_7 ) ;
V_4 -> V_45 = 1 ;
}
}
if ( V_4 -> V_45 ) {
V_4 -> V_45 = 0 ;
F_32 ( F_10 ( V_2 ) ) ;
}
}
int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & ( F_3 ( V_2 ) -> V_4 ) ;
int V_72 , V_71 ;
T_1 V_73 ;
struct V_10 * V_9 = F_10 ( V_2 ) ;
unsigned char * V_38 = F_2 ( V_2 ) + V_4 -> V_13 ;
struct V_6 * V_7 = F_17 ( V_2 ) ;
struct V_6 * V_75 ;
unsigned long V_76 ;
int V_77 ;
if ( ! V_7 )
return 0 ;
if ( V_2 -> V_78 != V_79 )
return - V_27 ;
if ( V_7 -> V_80 == V_31 ) {
if ( ! V_4 -> V_35 )
return 0 ;
F_21 ( V_2 , V_62 , 0 , F_15 ( 16 << 24 ) ) ;
return - V_27 ;
}
if ( V_7 -> V_80 != V_81 )
return - V_27 ;
for ( V_71 = V_38 [ 2 ] , V_72 = V_38 [ 1 ] ; V_71 <= V_72 ; V_71 += 4 ) {
if ( V_71 + 3 > V_72 ) {
F_21 ( V_2 , V_62 , 0 , F_15 ( ( V_4 -> V_13 + 2 ) << 24 ) ) ;
return - V_27 ;
}
memcpy ( & V_73 , & V_38 [ V_71 - 1 ] , 4 ) ;
V_76 = V_2 -> V_82 ;
F_34 ( V_2 , NULL ) ;
V_77 = F_35 ( V_2 , V_73 , V_9 -> V_34 , V_9 -> V_83 , V_2 -> V_30 ) ;
V_75 = F_17 ( V_2 ) ;
if ( V_77 || ( V_75 -> V_80 != V_31 && V_75 -> V_80 != V_81 ) ) {
F_36 ( V_2 ) ;
V_2 -> V_82 = V_76 ;
return - V_27 ;
}
F_37 ( V_76 ) ;
if ( V_75 -> V_80 != V_81 )
break;
V_9 -> V_5 = V_73 ;
V_4 -> V_45 = 1 ;
}
if ( V_71 <= V_72 ) {
V_4 -> V_70 = 1 ;
V_4 -> V_73 = V_73 ;
V_4 -> V_45 = 1 ;
}
return 0 ;
}
