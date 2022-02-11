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
int F_6 ( struct V_21 * V_21 , struct V_3 * V_22 ,
struct V_1 * V_2 , const struct V_3 * V_23 )
{
unsigned char * V_24 , * V_25 ;
int V_26 , V_27 ;
int V_12 ;
memset ( V_22 , 0 , sizeof( struct V_3 ) ) ;
if ( V_23 -> V_12 == 0 )
return 0 ;
V_24 = F_2 ( V_2 ) ;
V_25 = V_22 -> V_11 ;
if ( V_23 -> V_15 ) {
V_12 = V_24 [ V_23 -> V_15 + 1 ] ;
V_26 = V_24 [ V_23 -> V_15 + 2 ] ;
V_22 -> V_15 = V_22 -> V_12 + sizeof( struct V_10 ) ;
memcpy ( V_25 , V_24 + V_23 -> V_15 , V_12 ) ;
if ( V_23 -> V_14 && V_26 <= V_12 ) {
if ( V_26 + 3 > V_12 )
return - V_28 ;
V_25 [ 2 ] = V_26 + 4 ;
V_22 -> V_14 = 1 ;
}
V_25 += V_12 ;
V_22 -> V_12 += V_12 ;
}
if ( V_23 -> V_17 ) {
V_12 = V_24 [ V_23 -> V_17 + 1 ] ;
V_26 = V_24 [ V_23 -> V_17 + 2 ] ;
V_22 -> V_17 = V_22 -> V_12 + sizeof( struct V_10 ) ;
memcpy ( V_25 , V_24 + V_23 -> V_17 , V_12 ) ;
if ( V_26 <= V_12 ) {
if ( V_23 -> V_16 ) {
if ( V_26 + 3 > V_12 )
return - V_28 ;
V_22 -> V_16 = 1 ;
V_26 += 4 ;
}
if ( V_23 -> V_18 ) {
if ( V_26 + 3 > V_12 )
return - V_28 ;
if ( ( V_25 [ 3 ] & 0xF ) != V_29 ) {
V_22 -> V_18 = 1 ;
V_26 += 4 ;
} else {
V_22 -> V_18 = 0 ;
if ( V_26 + 7 <= V_12 ) {
T_1 V_30 ;
memcpy ( & V_30 , V_25 + V_26 - 1 , 4 ) ;
if ( F_7 ( V_21 , V_30 ) != V_31 ) {
V_22 -> V_18 = 1 ;
V_26 += 8 ;
}
}
}
}
V_25 [ 2 ] = V_26 ;
}
V_25 += V_12 ;
V_22 -> V_12 += V_12 ;
}
if ( V_23 -> V_13 ) {
unsigned char * V_32 = V_24 + V_23 -> V_13 ;
T_1 V_33 ;
V_12 = V_32 [ 1 ] ;
V_26 = V_32 [ 2 ] ;
V_27 = 0 ;
if ( V_26 > V_12 )
V_26 = V_12 + 1 ;
V_26 -= 4 ;
if ( V_26 > 3 ) {
memcpy ( & V_33 , & V_32 [ V_26 - 1 ] , 4 ) ;
for ( V_26 -= 4 , V_27 = 4 ; V_26 > 3 ; V_26 -= 4 , V_27 += 4 )
memcpy ( & V_25 [ V_27 - 1 ] , & V_32 [ V_26 - 1 ] , 4 ) ;
if ( memcmp ( & F_8 ( V_2 ) -> V_34 ,
& V_32 [ V_26 + 3 ] , 4 ) == 0 )
V_27 -= 4 ;
}
if ( V_27 > 3 ) {
V_22 -> V_33 = V_33 ;
V_25 [ 0 ] = V_32 [ 0 ] ;
V_25 [ 1 ] = V_27 + 3 ;
V_25 [ 2 ] = 4 ;
V_25 += V_27 + 3 ;
V_22 -> V_13 = V_22 -> V_12 + sizeof( struct V_10 ) ;
V_22 -> V_12 += V_27 + 3 ;
V_22 -> V_35 = V_23 -> V_35 ;
}
}
if ( V_23 -> V_36 ) {
V_12 = V_24 [ V_23 -> V_36 + 1 ] ;
V_22 -> V_36 = V_22 -> V_12 + sizeof( struct V_10 ) ;
memcpy ( V_25 , V_24 + V_23 -> V_36 , V_12 ) ;
V_25 += V_12 ;
V_22 -> V_12 += V_12 ;
}
while ( V_22 -> V_12 & 3 ) {
* V_25 ++ = V_37 ;
V_22 -> V_12 ++ ;
}
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
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
if ( ! F_10 ( * V_38 ) )
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
static void F_11 ( T_1 * V_41 , struct V_1 * V_2 )
{
if ( * V_41 == F_12 ( V_42 ) )
* V_41 = F_13 ( V_2 ) ;
}
int F_14 ( struct V_21 * V_21 ,
struct V_3 * V_4 , struct V_1 * V_2 )
{
T_1 V_41 = F_12 ( V_42 ) ;
unsigned char * V_43 = NULL ;
struct V_6 * V_7 = NULL ;
unsigned char * V_38 ;
unsigned char * V_9 ;
int V_12 , V_39 ;
if ( V_2 ) {
V_7 = F_15 ( V_2 ) ;
V_38 = ( unsigned char * ) & ( F_8 ( V_2 ) [ 1 ] ) ;
} else
V_38 = V_4 -> V_11 ;
V_9 = V_38 - sizeof( struct V_10 ) ;
for ( V_39 = V_4 -> V_12 ; V_39 > 0 ; ) {
switch ( * V_38 ) {
case V_37 :
for ( V_38 ++ , V_39 -- ; V_39 > 0 ; V_38 ++ , V_39 -- ) {
if ( * V_38 != V_37 ) {
* V_38 = V_37 ;
V_4 -> V_44 = 1 ;
}
}
goto V_45;
case V_40 :
V_39 -- ;
V_38 ++ ;
continue;
}
if ( F_16 ( V_39 < 2 ) ) {
V_43 = V_38 ;
goto error;
}
V_12 = V_38 [ 1 ] ;
if ( V_12 < 2 || V_12 > V_39 ) {
V_43 = V_38 ;
goto error;
}
switch ( * V_38 ) {
case V_46 :
case V_47 :
if ( V_12 < 3 ) {
V_43 = V_38 + 1 ;
goto error;
}
if ( V_38 [ 2 ] < 4 ) {
V_43 = V_38 + 2 ;
goto error;
}
if ( V_4 -> V_13 ) {
V_43 = V_38 ;
goto error;
}
if ( ! V_2 ) {
if ( V_38 [ 2 ] != 4 || V_12 < 7 || ( ( V_12 - 3 ) & 3 ) ) {
V_43 = V_38 + 1 ;
goto error;
}
memcpy ( & V_4 -> V_33 , & V_38 [ 3 ] , 4 ) ;
if ( V_12 > 7 )
memmove ( & V_38 [ 3 ] , & V_38 [ 7 ] , V_12 - 7 ) ;
}
V_4 -> V_35 = ( V_38 [ 0 ] == V_46 ) ;
V_4 -> V_13 = V_38 - V_9 ;
break;
case V_48 :
if ( V_4 -> V_15 ) {
V_43 = V_38 ;
goto error;
}
if ( V_12 < 3 ) {
V_43 = V_38 + 1 ;
goto error;
}
if ( V_38 [ 2 ] < 4 ) {
V_43 = V_38 + 2 ;
goto error;
}
if ( V_38 [ 2 ] <= V_12 ) {
if ( V_38 [ 2 ] + 3 > V_12 ) {
V_43 = V_38 + 2 ;
goto error;
}
if ( V_7 ) {
F_11 ( & V_41 , V_2 ) ;
memcpy ( & V_38 [ V_38 [ 2 ] - 1 ] , & V_41 , 4 ) ;
V_4 -> V_44 = 1 ;
}
V_38 [ 2 ] += 4 ;
V_4 -> V_14 = 1 ;
}
V_4 -> V_15 = V_38 - V_9 ;
break;
case V_49 :
if ( V_4 -> V_17 ) {
V_43 = V_38 ;
goto error;
}
if ( V_12 < 4 ) {
V_43 = V_38 + 1 ;
goto error;
}
if ( V_38 [ 2 ] < 5 ) {
V_43 = V_38 + 2 ;
goto error;
}
if ( V_38 [ 2 ] <= V_12 ) {
unsigned char * V_50 = NULL ;
if ( V_38 [ 2 ] + 3 > V_12 ) {
V_43 = V_38 + 2 ;
goto error;
}
switch ( V_38 [ 3 ] & 0xF ) {
case V_51 :
if ( V_2 )
V_50 = & V_38 [ V_38 [ 2 ] - 1 ] ;
V_4 -> V_18 = 1 ;
V_38 [ 2 ] += 4 ;
break;
case V_52 :
if ( V_38 [ 2 ] + 7 > V_12 ) {
V_43 = V_38 + 2 ;
goto error;
}
if ( V_7 ) {
F_11 ( & V_41 , V_2 ) ;
memcpy ( & V_38 [ V_38 [ 2 ] - 1 ] , & V_41 , 4 ) ;
V_50 = & V_38 [ V_38 [ 2 ] + 3 ] ;
}
V_4 -> V_16 = 1 ;
V_4 -> V_18 = 1 ;
V_38 [ 2 ] += 8 ;
break;
case V_29 :
if ( V_38 [ 2 ] + 7 > V_12 ) {
V_43 = V_38 + 2 ;
goto error;
}
{
T_1 V_30 ;
memcpy ( & V_30 , & V_38 [ V_38 [ 2 ] - 1 ] , 4 ) ;
if ( F_7 ( V_21 , V_30 ) == V_31 )
break;
if ( V_2 )
V_50 = & V_38 [ V_38 [ 2 ] + 3 ] ;
}
V_4 -> V_18 = 1 ;
V_38 [ 2 ] += 8 ;
break;
default:
if ( ! V_2 && ! F_17 ( V_21 -> V_53 , V_54 ) ) {
V_43 = V_38 + 3 ;
goto error;
}
break;
}
if ( V_50 ) {
T_1 V_19 ;
V_19 = F_5 () ;
memcpy ( V_50 , & V_19 , 4 ) ;
V_4 -> V_44 = 1 ;
}
} else if ( ( V_38 [ 3 ] & 0xF ) != V_29 ) {
unsigned int V_55 = V_38 [ 3 ] >> 4 ;
if ( V_55 == 15 ) {
V_43 = V_38 + 3 ;
goto error;
}
if ( V_2 ) {
V_38 [ 3 ] = ( V_38 [ 3 ] & 0xF ) | ( ( V_55 + 1 ) << 4 ) ;
V_4 -> V_44 = 1 ;
}
}
V_4 -> V_17 = V_38 - V_9 ;
break;
case V_56 :
if ( V_12 < 4 ) {
V_43 = V_38 + 1 ;
goto error;
}
if ( V_38 [ 2 ] == 0 && V_38 [ 3 ] == 0 )
V_4 -> V_57 = V_38 - V_9 ;
break;
case V_58 :
if ( ( ! V_2 && ! F_17 ( V_21 -> V_53 , V_54 ) ) || V_4 -> V_36 ) {
V_43 = V_38 ;
goto error;
}
V_4 -> V_36 = V_38 - V_9 ;
if ( F_18 ( V_2 , & V_38 ) ) {
V_43 = V_38 ;
goto error;
}
break;
case V_59 :
case V_60 :
default:
if ( ! V_2 && ! F_17 ( V_21 -> V_53 , V_54 ) ) {
V_43 = V_38 ;
goto error;
}
break;
}
V_39 -= V_12 ;
V_38 += V_12 ;
}
V_45:
if ( ! V_43 )
return 0 ;
error:
if ( V_2 ) {
F_19 ( V_2 , V_61 , 0 , F_12 ( ( V_43 - V_9 ) << 24 ) ) ;
}
return - V_28 ;
}
void F_20 ( struct V_3 * V_4 )
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
if ( ( V_38 [ 3 ] & 0xF ) == V_29 )
V_38 [ 2 ] -= 4 ;
}
if ( V_4 -> V_16 ) {
V_38 [ 2 ] -= 4 ;
memset ( & V_38 [ V_38 [ 2 ] - 1 ] , 0 , 4 ) ;
}
}
}
static struct V_62 * F_21 ( const int V_12 )
{
return F_22 ( sizeof( struct V_62 ) + ( ( V_12 + 3 ) & ~ 3 ) ,
V_63 ) ;
}
static int F_23 ( struct V_21 * V_21 , struct V_62 * * V_64 ,
struct V_62 * V_4 , int V_12 )
{
while ( V_12 & 3 )
V_4 -> V_4 . V_11 [ V_12 ++ ] = V_37 ;
V_4 -> V_4 . V_12 = V_12 ;
if ( V_12 && F_14 ( V_21 , & V_4 -> V_4 , NULL ) ) {
F_24 ( V_4 ) ;
return - V_28 ;
}
F_24 ( * V_64 ) ;
* V_64 = V_4 ;
return 0 ;
}
int F_25 ( struct V_21 * V_21 , struct V_62 * * V_64 ,
unsigned char T_2 * V_65 , int V_12 )
{
struct V_62 * V_4 = F_21 ( V_12 ) ;
if ( ! V_4 )
return - V_66 ;
if ( V_12 && F_26 ( V_4 -> V_4 . V_11 , V_65 , V_12 ) ) {
F_24 ( V_4 ) ;
return - V_67 ;
}
return F_23 ( V_21 , V_64 , V_4 , V_12 ) ;
}
int F_27 ( struct V_21 * V_21 , struct V_62 * * V_64 ,
unsigned char * V_65 , int V_12 )
{
struct V_62 * V_4 = F_21 ( V_12 ) ;
if ( ! V_4 )
return - V_66 ;
if ( V_12 )
memcpy ( V_4 -> V_4 . V_11 , V_65 , V_12 ) ;
return F_23 ( V_21 , V_64 , V_4 , V_12 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & ( F_3 ( V_2 ) -> V_4 ) ;
unsigned char * V_38 ;
struct V_6 * V_7 = F_15 ( V_2 ) ;
unsigned char * V_68 = F_2 ( V_2 ) ;
if ( V_4 -> V_14 ) {
V_38 = ( unsigned char * ) V_68 + V_4 -> V_15 ;
F_4 ( & V_38 [ V_38 [ 2 ] - 5 ] , V_2 , V_7 ) ;
V_4 -> V_44 = 1 ;
}
if ( V_4 -> V_69 ) {
int V_70 , V_71 ;
V_38 = V_68 + V_4 -> V_13 ;
for ( V_70 = V_38 [ 2 ] , V_71 = V_38 [ 1 ] ;
V_70 <= V_71 ;
V_70 += 4
) {
if ( V_70 + 3 > V_71 )
break;
if ( memcmp ( & V_4 -> V_72 , & V_38 [ V_70 - 1 ] , 4 ) == 0 )
break;
}
if ( V_70 + 3 <= V_71 ) {
V_4 -> V_44 = 1 ;
F_8 ( V_2 ) -> V_5 = V_4 -> V_72 ;
F_4 ( & V_38 [ V_70 - 1 ] , V_2 , V_7 ) ;
V_38 [ 2 ] = V_70 + 4 ;
} else {
F_29 ( L_1 ,
V_73 ) ;
}
if ( V_4 -> V_16 ) {
V_38 = V_68 + V_4 -> V_17 ;
F_4 ( & V_38 [ V_38 [ 2 ] - 9 ] , V_2 , V_7 ) ;
V_4 -> V_44 = 1 ;
}
}
if ( V_4 -> V_44 ) {
V_4 -> V_44 = 0 ;
F_30 ( F_8 ( V_2 ) ) ;
}
}
int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & ( F_3 ( V_2 ) -> V_4 ) ;
int V_71 , V_70 ;
T_1 V_72 ;
struct V_10 * V_9 = F_8 ( V_2 ) ;
unsigned char * V_38 = F_2 ( V_2 ) + V_4 -> V_13 ;
struct V_6 * V_7 = F_15 ( V_2 ) ;
struct V_6 * V_74 ;
unsigned long V_75 ;
int V_76 ;
if ( ! V_7 )
return 0 ;
if ( V_2 -> V_77 != V_78 )
return - V_28 ;
if ( V_7 -> V_79 == V_31 ) {
if ( ! V_4 -> V_35 )
return 0 ;
F_19 ( V_2 , V_61 , 0 , F_12 ( 16 << 24 ) ) ;
return - V_28 ;
}
if ( V_7 -> V_79 != V_80 )
return - V_28 ;
for ( V_70 = V_38 [ 2 ] , V_71 = V_38 [ 1 ] ; V_70 <= V_71 ; V_70 += 4 ) {
if ( V_70 + 3 > V_71 ) {
F_19 ( V_2 , V_61 , 0 , F_12 ( ( V_4 -> V_13 + 2 ) << 24 ) ) ;
return - V_28 ;
}
memcpy ( & V_72 , & V_38 [ V_70 - 1 ] , 4 ) ;
V_75 = V_2 -> V_81 ;
F_32 ( V_2 , NULL ) ;
V_76 = F_33 ( V_2 , V_72 , V_9 -> V_34 , V_9 -> V_82 , V_2 -> V_83 ) ;
V_74 = F_15 ( V_2 ) ;
if ( V_76 || ( V_74 -> V_79 != V_31 && V_74 -> V_79 != V_80 ) ) {
F_34 ( V_2 ) ;
V_2 -> V_81 = V_75 ;
return - V_28 ;
}
F_35 ( V_75 ) ;
if ( V_74 -> V_79 != V_80 )
break;
V_9 -> V_5 = V_72 ;
V_4 -> V_44 = 1 ;
}
if ( V_70 <= V_71 ) {
V_4 -> V_69 = 1 ;
V_4 -> V_72 = V_72 ;
V_4 -> V_44 = 1 ;
}
return 0 ;
}
