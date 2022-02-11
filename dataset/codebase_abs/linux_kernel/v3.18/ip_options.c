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
int F_7 ( struct V_3 * V_27 , struct V_1 * V_2 ,
const struct V_3 * V_28 )
{
unsigned char * V_29 , * V_30 ;
int V_31 , V_32 ;
int V_12 ;
memset ( V_27 , 0 , sizeof( struct V_3 ) ) ;
if ( V_28 -> V_12 == 0 )
return 0 ;
V_29 = F_2 ( V_2 ) ;
V_30 = V_27 -> V_11 ;
if ( V_28 -> V_15 ) {
V_12 = V_29 [ V_28 -> V_15 + 1 ] ;
V_31 = V_29 [ V_28 -> V_15 + 2 ] ;
V_27 -> V_15 = V_27 -> V_12 + sizeof( struct V_10 ) ;
memcpy ( V_30 , V_29 + V_28 -> V_15 , V_12 ) ;
if ( V_28 -> V_14 && V_31 <= V_12 ) {
if ( V_31 + 3 > V_12 )
return - V_33 ;
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
return - V_33 ;
V_27 -> V_16 = 1 ;
V_31 += 4 ;
}
if ( V_28 -> V_18 ) {
if ( V_31 + 3 > V_12 )
return - V_33 ;
if ( ( V_30 [ 3 ] & 0xF ) != V_34 ) {
V_27 -> V_18 = 1 ;
V_31 += 4 ;
} else {
V_27 -> V_18 = 0 ;
if ( V_31 + 7 <= V_12 ) {
T_1 V_35 ;
memcpy ( & V_35 , V_30 + V_31 - 1 , 4 ) ;
if ( F_8 ( F_9 ( F_10 ( V_2 ) -> V_36 ) , V_35 ) != V_37 ) {
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
unsigned char * V_38 = V_29 + V_28 -> V_13 ;
T_1 V_39 ;
V_12 = V_38 [ 1 ] ;
V_31 = V_38 [ 2 ] ;
V_32 = 0 ;
if ( V_31 > V_12 )
V_31 = V_12 + 1 ;
V_31 -= 4 ;
if ( V_31 > 3 ) {
memcpy ( & V_39 , & V_38 [ V_31 - 1 ] , 4 ) ;
for ( V_31 -= 4 , V_32 = 4 ; V_31 > 3 ; V_31 -= 4 , V_32 += 4 )
memcpy ( & V_30 [ V_32 - 1 ] , & V_38 [ V_31 - 1 ] , 4 ) ;
if ( memcmp ( & F_11 ( V_2 ) -> V_40 ,
& V_38 [ V_31 + 3 ] , 4 ) == 0 )
V_32 -= 4 ;
}
if ( V_32 > 3 ) {
T_1 V_5 = F_12 ( V_2 ) ;
memcpy ( & V_38 [ V_32 - 1 ] , & V_5 , 4 ) ;
V_27 -> V_39 = V_39 ;
V_30 [ 0 ] = V_38 [ 0 ] ;
V_30 [ 1 ] = V_32 + 3 ;
V_30 [ 2 ] = 4 ;
V_30 += V_32 + 3 ;
V_27 -> V_13 = V_27 -> V_12 + sizeof( struct V_10 ) ;
V_27 -> V_12 += V_32 + 3 ;
V_27 -> V_41 = V_28 -> V_41 ;
}
}
if ( V_28 -> V_42 ) {
V_12 = V_29 [ V_28 -> V_42 + 1 ] ;
V_27 -> V_42 = V_27 -> V_12 + sizeof( struct V_10 ) ;
memcpy ( V_30 , V_29 + V_28 -> V_42 , V_12 ) ;
V_30 += V_12 ;
V_27 -> V_12 += V_12 ;
}
while ( V_27 -> V_12 & 3 ) {
* V_30 ++ = V_43 ;
V_27 -> V_12 ++ ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
unsigned char * V_44 = F_2 ( V_2 ) + sizeof( struct V_10 ) ;
struct V_3 * V_4 = & ( F_3 ( V_2 ) -> V_4 ) ;
int V_45 = V_4 -> V_12 ;
int V_12 ;
while ( V_45 > 0 ) {
switch ( * V_44 ) {
case V_43 :
return;
case V_46 :
V_45 -- ;
V_44 ++ ;
continue;
}
V_12 = V_44 [ 1 ] ;
if ( V_12 < 2 || V_12 > V_45 )
return;
if ( ! F_14 ( * V_44 ) )
memset ( V_44 , V_46 , V_12 ) ;
V_45 -= V_12 ;
V_44 += V_12 ;
}
V_4 -> V_17 = 0 ;
V_4 -> V_15 = 0 ;
V_4 -> V_14 = 0 ;
V_4 -> V_16 = 0 ;
V_4 -> V_18 = 0 ;
}
static void F_15 ( T_1 * V_47 , struct V_1 * V_2 )
{
if ( * V_47 == F_6 ( V_48 ) )
* V_47 = F_12 ( V_2 ) ;
}
int F_16 ( struct V_49 * V_49 ,
struct V_3 * V_4 , struct V_1 * V_2 )
{
T_1 V_47 = F_6 ( V_48 ) ;
unsigned char * V_50 = NULL ;
struct V_6 * V_7 = NULL ;
unsigned char * V_44 ;
unsigned char * V_9 ;
int V_12 , V_45 ;
if ( V_2 != NULL ) {
V_7 = F_17 ( V_2 ) ;
V_44 = ( unsigned char * ) & ( F_11 ( V_2 ) [ 1 ] ) ;
} else
V_44 = V_4 -> V_11 ;
V_9 = V_44 - sizeof( struct V_10 ) ;
for ( V_45 = V_4 -> V_12 ; V_45 > 0 ; ) {
switch ( * V_44 ) {
case V_43 :
for ( V_44 ++ , V_45 -- ; V_45 > 0 ; V_44 ++ , V_45 -- ) {
if ( * V_44 != V_43 ) {
* V_44 = V_43 ;
V_4 -> V_51 = 1 ;
}
}
goto V_52;
case V_46 :
V_45 -- ;
V_44 ++ ;
continue;
}
if ( F_18 ( V_45 < 2 ) ) {
V_50 = V_44 ;
goto error;
}
V_12 = V_44 [ 1 ] ;
if ( V_12 < 2 || V_12 > V_45 ) {
V_50 = V_44 ;
goto error;
}
switch ( * V_44 ) {
case V_53 :
case V_54 :
if ( V_12 < 3 ) {
V_50 = V_44 + 1 ;
goto error;
}
if ( V_44 [ 2 ] < 4 ) {
V_50 = V_44 + 2 ;
goto error;
}
if ( V_4 -> V_13 ) {
V_50 = V_44 ;
goto error;
}
if ( ! V_2 ) {
if ( V_44 [ 2 ] != 4 || V_12 < 7 || ( ( V_12 - 3 ) & 3 ) ) {
V_50 = V_44 + 1 ;
goto error;
}
memcpy ( & V_4 -> V_39 , & V_44 [ 3 ] , 4 ) ;
if ( V_12 > 7 )
memmove ( & V_44 [ 3 ] , & V_44 [ 7 ] , V_12 - 7 ) ;
}
V_4 -> V_41 = ( V_44 [ 0 ] == V_53 ) ;
V_4 -> V_13 = V_44 - V_9 ;
break;
case V_55 :
if ( V_4 -> V_15 ) {
V_50 = V_44 ;
goto error;
}
if ( V_12 < 3 ) {
V_50 = V_44 + 1 ;
goto error;
}
if ( V_44 [ 2 ] < 4 ) {
V_50 = V_44 + 2 ;
goto error;
}
if ( V_44 [ 2 ] <= V_12 ) {
if ( V_44 [ 2 ] + 3 > V_12 ) {
V_50 = V_44 + 2 ;
goto error;
}
if ( V_7 ) {
F_15 ( & V_47 , V_2 ) ;
memcpy ( & V_44 [ V_44 [ 2 ] - 1 ] , & V_47 , 4 ) ;
V_4 -> V_51 = 1 ;
}
V_44 [ 2 ] += 4 ;
V_4 -> V_14 = 1 ;
}
V_4 -> V_15 = V_44 - V_9 ;
break;
case V_56 :
if ( V_4 -> V_17 ) {
V_50 = V_44 ;
goto error;
}
if ( V_12 < 4 ) {
V_50 = V_44 + 1 ;
goto error;
}
if ( V_44 [ 2 ] < 5 ) {
V_50 = V_44 + 2 ;
goto error;
}
if ( V_44 [ 2 ] <= V_12 ) {
unsigned char * V_57 = NULL ;
if ( V_44 [ 2 ] + 3 > V_12 ) {
V_50 = V_44 + 2 ;
goto error;
}
switch ( V_44 [ 3 ] & 0xF ) {
case V_58 :
if ( V_2 )
V_57 = & V_44 [ V_44 [ 2 ] - 1 ] ;
V_4 -> V_18 = 1 ;
V_44 [ 2 ] += 4 ;
break;
case V_59 :
if ( V_44 [ 2 ] + 7 > V_12 ) {
V_50 = V_44 + 2 ;
goto error;
}
if ( V_7 ) {
F_15 ( & V_47 , V_2 ) ;
memcpy ( & V_44 [ V_44 [ 2 ] - 1 ] , & V_47 , 4 ) ;
V_57 = & V_44 [ V_44 [ 2 ] + 3 ] ;
}
V_4 -> V_16 = 1 ;
V_4 -> V_18 = 1 ;
V_44 [ 2 ] += 8 ;
break;
case V_34 :
if ( V_44 [ 2 ] + 7 > V_12 ) {
V_50 = V_44 + 2 ;
goto error;
}
{
T_1 V_35 ;
memcpy ( & V_35 , & V_44 [ V_44 [ 2 ] - 1 ] , 4 ) ;
if ( F_8 ( V_49 , V_35 ) == V_37 )
break;
if ( V_2 )
V_57 = & V_44 [ V_44 [ 2 ] + 3 ] ;
}
V_4 -> V_18 = 1 ;
V_44 [ 2 ] += 8 ;
break;
default:
if ( ! V_2 && ! F_19 ( V_49 -> V_60 , V_61 ) ) {
V_50 = V_44 + 3 ;
goto error;
}
break;
}
if ( V_57 ) {
struct V_19 V_20 ;
T_2 V_21 ;
F_5 ( & V_20 ) ;
V_21 = ( V_20 . V_22 % 86400 ) * V_23 + V_20 . V_24 / V_25 ;
F_20 ( V_21 , V_57 ) ;
V_4 -> V_51 = 1 ;
}
} else if ( ( V_44 [ 3 ] & 0xF ) != V_34 ) {
unsigned int V_62 = V_44 [ 3 ] >> 4 ;
if ( V_62 == 15 ) {
V_50 = V_44 + 3 ;
goto error;
}
if ( V_2 ) {
V_44 [ 3 ] = ( V_44 [ 3 ] & 0xF ) | ( ( V_62 + 1 ) << 4 ) ;
V_4 -> V_51 = 1 ;
}
}
V_4 -> V_17 = V_44 - V_9 ;
break;
case V_63 :
if ( V_12 < 4 ) {
V_50 = V_44 + 1 ;
goto error;
}
if ( V_44 [ 2 ] == 0 && V_44 [ 3 ] == 0 )
V_4 -> V_64 = V_44 - V_9 ;
break;
case V_65 :
if ( ( ! V_2 && ! F_19 ( V_49 -> V_60 , V_61 ) ) || V_4 -> V_42 ) {
V_50 = V_44 ;
goto error;
}
V_4 -> V_42 = V_44 - V_9 ;
if ( F_21 ( V_2 , & V_44 ) ) {
V_50 = V_44 ;
goto error;
}
break;
case V_66 :
case V_67 :
default:
if ( ! V_2 && ! F_19 ( V_49 -> V_60 , V_61 ) ) {
V_50 = V_44 ;
goto error;
}
break;
}
V_45 -= V_12 ;
V_44 += V_12 ;
}
V_52:
if ( ! V_50 )
return 0 ;
error:
if ( V_2 ) {
F_22 ( V_2 , V_68 , 0 , F_6 ( ( V_50 - V_9 ) << 24 ) ) ;
}
return - V_33 ;
}
void F_23 ( struct V_3 * V_4 )
{
if ( V_4 -> V_13 ) {
unsigned char * V_44 = V_4 -> V_11 + V_4 -> V_13 - sizeof( struct V_10 ) ;
memmove ( V_44 + 7 , V_44 + 3 , V_44 [ 1 ] - 7 ) ;
memcpy ( V_44 + 3 , & V_4 -> V_39 , 4 ) ;
}
if ( V_4 -> V_14 ) {
unsigned char * V_44 = V_4 -> V_11 + V_4 -> V_15 - sizeof( struct V_10 ) ;
V_44 [ 2 ] -= 4 ;
memset ( & V_44 [ V_44 [ 2 ] - 1 ] , 0 , 4 ) ;
}
if ( V_4 -> V_17 ) {
unsigned char * V_44 = V_4 -> V_11 + V_4 -> V_17 - sizeof( struct V_10 ) ;
if ( V_4 -> V_18 ) {
V_44 [ 2 ] -= 4 ;
memset ( & V_44 [ V_44 [ 2 ] - 1 ] , 0 , 4 ) ;
if ( ( V_44 [ 3 ] & 0xF ) == V_34 )
V_44 [ 2 ] -= 4 ;
}
if ( V_4 -> V_16 ) {
V_44 [ 2 ] -= 4 ;
memset ( & V_44 [ V_44 [ 2 ] - 1 ] , 0 , 4 ) ;
}
}
}
static struct V_69 * F_24 ( const int V_12 )
{
return F_25 ( sizeof( struct V_69 ) + ( ( V_12 + 3 ) & ~ 3 ) ,
V_70 ) ;
}
static int F_26 ( struct V_49 * V_49 , struct V_69 * * V_71 ,
struct V_69 * V_4 , int V_12 )
{
while ( V_12 & 3 )
V_4 -> V_4 . V_11 [ V_12 ++ ] = V_43 ;
V_4 -> V_4 . V_12 = V_12 ;
if ( V_12 && F_16 ( V_49 , & V_4 -> V_4 , NULL ) ) {
F_27 ( V_4 ) ;
return - V_33 ;
}
F_27 ( * V_71 ) ;
* V_71 = V_4 ;
return 0 ;
}
int F_28 ( struct V_49 * V_49 , struct V_69 * * V_71 ,
unsigned char T_3 * V_72 , int V_12 )
{
struct V_69 * V_4 = F_24 ( V_12 ) ;
if ( ! V_4 )
return - V_73 ;
if ( V_12 && F_29 ( V_4 -> V_4 . V_11 , V_72 , V_12 ) ) {
F_27 ( V_4 ) ;
return - V_74 ;
}
return F_26 ( V_49 , V_71 , V_4 , V_12 ) ;
}
int F_30 ( struct V_49 * V_49 , struct V_69 * * V_71 ,
unsigned char * V_72 , int V_12 )
{
struct V_69 * V_4 = F_24 ( V_12 ) ;
if ( ! V_4 )
return - V_73 ;
if ( V_12 )
memcpy ( V_4 -> V_4 . V_11 , V_72 , V_12 ) ;
return F_26 ( V_49 , V_71 , V_4 , V_12 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & ( F_3 ( V_2 ) -> V_4 ) ;
unsigned char * V_44 ;
struct V_6 * V_7 = F_17 ( V_2 ) ;
unsigned char * V_75 = F_2 ( V_2 ) ;
if ( V_4 -> V_14 ) {
V_44 = ( unsigned char * ) V_75 + V_4 -> V_15 ;
F_4 ( & V_44 [ V_44 [ 2 ] - 5 ] , V_2 , V_7 ) ;
V_4 -> V_51 = 1 ;
}
if ( V_4 -> V_76 ) {
int V_77 , V_78 ;
V_44 = V_75 + V_4 -> V_13 ;
for ( V_77 = V_44 [ 2 ] , V_78 = V_44 [ 1 ] ;
V_77 <= V_78 ;
V_77 += 4
) {
if ( V_77 + 3 > V_78 )
break;
if ( memcmp ( & V_4 -> V_79 , & V_44 [ V_77 - 1 ] , 4 ) == 0 )
break;
}
if ( V_77 + 3 <= V_78 ) {
V_4 -> V_51 = 1 ;
F_11 ( V_2 ) -> V_5 = V_4 -> V_79 ;
F_4 ( & V_44 [ V_77 - 1 ] , V_2 , V_7 ) ;
V_44 [ 2 ] = V_77 + 4 ;
} else {
F_32 ( L_1 ,
V_80 ) ;
}
if ( V_4 -> V_16 ) {
V_44 = V_75 + V_4 -> V_17 ;
F_4 ( & V_44 [ V_44 [ 2 ] - 9 ] , V_2 , V_7 ) ;
V_4 -> V_51 = 1 ;
}
}
if ( V_4 -> V_51 ) {
V_4 -> V_51 = 0 ;
F_33 ( F_11 ( V_2 ) ) ;
}
}
int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & ( F_3 ( V_2 ) -> V_4 ) ;
int V_78 , V_77 ;
T_1 V_79 ;
struct V_10 * V_9 = F_11 ( V_2 ) ;
unsigned char * V_44 = F_2 ( V_2 ) + V_4 -> V_13 ;
struct V_6 * V_7 = F_17 ( V_2 ) ;
struct V_6 * V_81 ;
unsigned long V_82 ;
int V_83 ;
if ( ! V_7 )
return 0 ;
if ( V_2 -> V_84 != V_85 )
return - V_33 ;
if ( V_7 -> V_86 == V_37 ) {
if ( ! V_4 -> V_41 )
return 0 ;
F_22 ( V_2 , V_68 , 0 , F_6 ( 16 << 24 ) ) ;
return - V_33 ;
}
if ( V_7 -> V_86 != V_87 )
return - V_33 ;
for ( V_77 = V_44 [ 2 ] , V_78 = V_44 [ 1 ] ; V_77 <= V_78 ; V_77 += 4 ) {
if ( V_77 + 3 > V_78 ) {
F_22 ( V_2 , V_68 , 0 , F_6 ( ( V_4 -> V_13 + 2 ) << 24 ) ) ;
return - V_33 ;
}
memcpy ( & V_79 , & V_44 [ V_77 - 1 ] , 4 ) ;
V_82 = V_2 -> V_88 ;
F_35 ( V_2 , NULL ) ;
V_83 = F_36 ( V_2 , V_79 , V_9 -> V_40 , V_9 -> V_89 , V_2 -> V_36 ) ;
V_81 = F_17 ( V_2 ) ;
if ( V_83 || ( V_81 -> V_86 != V_37 && V_81 -> V_86 != V_87 ) ) {
F_37 ( V_2 ) ;
V_2 -> V_88 = V_82 ;
return - V_33 ;
}
F_38 ( V_82 ) ;
if ( V_81 -> V_86 != V_87 )
break;
V_9 -> V_5 = V_79 ;
V_4 -> V_51 = 1 ;
}
if ( V_77 <= V_78 ) {
V_4 -> V_76 = 1 ;
V_4 -> V_79 = V_79 ;
V_4 -> V_51 = 1 ;
}
return 0 ;
}
