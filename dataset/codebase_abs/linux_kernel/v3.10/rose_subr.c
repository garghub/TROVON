void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & F_3 ( V_2 ) -> V_4 ) ;
}
void F_4 ( struct V_1 * V_2 , unsigned short V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( V_9 -> V_10 != V_5 ) {
while ( F_5 ( & V_9 -> V_4 ) != NULL && V_9 -> V_10 != V_5 ) {
V_7 = F_6 ( & V_9 -> V_4 ) ;
F_7 ( V_7 ) ;
V_9 -> V_10 = ( V_9 -> V_10 + 1 ) % V_11 ;
}
}
}
void F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 , * V_12 = NULL ;
while ( ( V_7 = F_6 ( & F_3 ( V_2 ) -> V_4 ) ) != NULL ) {
if ( V_12 == NULL )
F_9 ( & V_2 -> V_3 , V_7 ) ;
else
F_10 ( V_12 , V_7 , & V_2 -> V_3 ) ;
V_12 = V_7 ;
}
}
int F_11 ( struct V_1 * V_2 , unsigned short V_5 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
unsigned short V_13 = V_9 -> V_10 ;
while ( V_13 != V_9 -> V_14 ) {
if ( V_5 == V_13 ) return 1 ;
V_13 = ( V_13 + 1 ) % V_11 ;
}
return V_5 == V_9 -> V_14 ;
}
void F_12 ( struct V_1 * V_2 , int V_15 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_6 * V_7 ;
unsigned char * V_16 ;
unsigned char V_17 , V_18 ;
char V_19 [ 100 ] ;
int V_20 , V_21 = 0 ;
V_20 = V_22 + V_23 + V_24 + 1 ;
switch ( V_15 ) {
case V_25 :
V_20 += 1 + V_26 + V_26 ;
V_21 = F_13 ( V_19 , V_9 ) ;
V_20 += V_21 ;
break;
case V_27 :
case V_28 :
case V_29 :
V_20 += 2 ;
break;
}
if ( ( V_7 = F_14 ( V_20 , V_30 ) ) == NULL )
return;
F_15 ( V_7 , V_22 + V_23 + 1 ) ;
V_16 = F_16 ( V_7 , F_17 ( V_7 ) ) ;
V_17 = ( V_9 -> V_31 >> 8 ) & 0x0F ;
V_18 = ( V_9 -> V_31 >> 0 ) & 0xFF ;
switch ( V_15 ) {
case V_25 :
* V_16 ++ = V_32 | V_17 ;
* V_16 ++ = V_18 ;
* V_16 ++ = V_15 ;
* V_16 ++ = V_33 ;
memcpy ( V_16 , & V_9 -> V_34 , V_26 ) ;
V_16 += V_26 ;
memcpy ( V_16 , & V_9 -> V_35 , V_26 ) ;
V_16 += V_26 ;
memcpy ( V_16 , V_19 , V_21 ) ;
V_16 += V_21 ;
break;
case V_27 :
* V_16 ++ = V_32 | V_17 ;
* V_16 ++ = V_18 ;
* V_16 ++ = V_15 ;
* V_16 ++ = 0x00 ;
* V_16 ++ = 0 ;
break;
case V_28 :
* V_16 ++ = V_32 | V_17 ;
* V_16 ++ = V_18 ;
* V_16 ++ = V_15 ;
* V_16 ++ = V_9 -> V_36 ;
* V_16 ++ = V_9 -> V_37 ;
break;
case V_29 :
* V_16 ++ = V_32 | V_17 ;
* V_16 ++ = V_18 ;
* V_16 ++ = V_15 ;
* V_16 ++ = V_38 ;
* V_16 ++ = 0 ;
break;
case V_39 :
case V_40 :
* V_16 ++ = V_32 | V_17 ;
* V_16 ++ = V_18 ;
* V_16 = V_15 ;
* V_16 ++ |= ( V_9 -> V_41 << 5 ) & 0xE0 ;
break;
case V_42 :
case V_43 :
* V_16 ++ = V_32 | V_17 ;
* V_16 ++ = V_18 ;
* V_16 ++ = V_15 ;
break;
default:
F_18 ( V_44 L_1 , V_15 ) ;
F_7 ( V_7 ) ;
return;
}
F_19 ( V_7 , V_9 -> V_45 ) ;
}
int F_20 ( struct V_6 * V_7 , int * V_46 , int * V_5 , int * V_47 , int * V_48 , int * V_49 )
{
unsigned char * V_50 ;
V_50 = V_7 -> V_51 ;
* V_46 = * V_5 = * V_47 = * V_48 = * V_49 = 0 ;
switch ( V_50 [ 2 ] ) {
case V_25 :
case V_27 :
case V_28 :
case V_42 :
case V_29 :
case V_43 :
return V_50 [ 2 ] ;
default:
break;
}
if ( ( V_50 [ 2 ] & 0x1F ) == V_39 ||
( V_50 [ 2 ] & 0x1F ) == V_40 ) {
* V_5 = ( V_50 [ 2 ] >> 5 ) & 0x07 ;
return V_50 [ 2 ] & 0x1F ;
}
if ( ( V_50 [ 2 ] & 0x01 ) == V_52 ) {
* V_47 = ( V_50 [ 0 ] & V_53 ) == V_53 ;
* V_48 = ( V_50 [ 0 ] & V_54 ) == V_54 ;
* V_49 = ( V_50 [ 2 ] & V_55 ) == V_55 ;
* V_5 = ( V_50 [ 2 ] >> 5 ) & 0x07 ;
* V_46 = ( V_50 [ 2 ] >> 1 ) & 0x07 ;
return V_52 ;
}
return V_56 ;
}
static int F_21 ( unsigned char * V_57 , struct V_58 * V_59 , int V_20 )
{
unsigned char * V_60 ;
unsigned char V_61 , V_62 , V_63 = 0 ;
int V_64 = 0 ;
do {
switch ( * V_57 & 0xC0 ) {
case 0x00 :
if ( V_20 < 2 )
return - 1 ;
V_57 += 2 ;
V_63 += 2 ;
V_20 -= 2 ;
break;
case 0x40 :
if ( V_20 < 3 )
return - 1 ;
if ( * V_57 == V_65 )
V_59 -> rand = ( ( V_57 [ 1 ] << 8 ) & 0xFF00 ) + ( ( V_57 [ 2 ] << 0 ) & 0x00FF ) ;
V_57 += 3 ;
V_63 += 3 ;
V_20 -= 3 ;
break;
case 0x80 :
if ( V_20 < 4 )
return - 1 ;
V_57 += 4 ;
V_63 += 4 ;
V_20 -= 4 ;
break;
case 0xC0 :
if ( V_20 < 2 )
return - 1 ;
V_61 = V_57 [ 1 ] ;
if ( V_20 < 2 + V_61 )
return - 1 ;
if ( * V_57 == V_66 ) {
if ( ! V_64 ) {
if ( V_61 < V_67 )
return - 1 ;
memcpy ( & V_59 -> V_68 [ 0 ] , V_57 + 2 , V_67 ) ;
V_59 -> V_69 = 1 ;
}
}
else if ( * V_57 == V_70 ) {
if ( ! V_64 ) {
if ( V_61 < V_67 )
return - 1 ;
memcpy ( & V_59 -> V_71 [ 0 ] , V_57 + 2 , V_67 ) ;
V_59 -> V_72 = 1 ;
}
}
else if ( * V_57 == V_73 ) {
if ( V_61 < V_67 )
return - 1 ;
memcpy ( & V_59 -> V_74 , V_57 + 2 , V_67 ) ;
}
else if ( * V_57 == V_75 ) {
if ( V_61 < 1 + V_26 )
return - 1 ;
memcpy ( & V_59 -> V_76 , V_57 + 3 , V_26 ) ;
}
else if ( * V_57 == V_77 ) {
if ( V_61 % V_67 )
return - 1 ;
V_64 = 1 ;
V_59 -> V_69 = 0 ;
V_59 -> V_72 = 0 ;
for ( V_60 = V_57 + 2 , V_62 = 0 ; V_62 < V_61 ; V_60 += V_67 , V_62 += V_67 ) {
if ( V_60 [ 6 ] & V_78 ) {
if ( V_59 -> V_72 >= V_79 )
return - 1 ;
memcpy ( & V_59 -> V_71 [ V_59 -> V_72 ++ ] , V_60 , V_67 ) ;
} else {
if ( V_59 -> V_69 >= V_79 )
return - 1 ;
memcpy ( & V_59 -> V_68 [ V_59 -> V_69 ++ ] , V_60 , V_67 ) ;
}
}
}
V_57 += V_61 + 2 ;
V_63 += V_61 + 2 ;
V_20 -= V_61 + 2 ;
break;
}
} while ( * V_57 != 0x00 && V_20 > 0 );
return V_63 ;
}
static int F_22 ( unsigned char * V_57 , struct V_58 * V_59 , int V_20 )
{
unsigned char V_61 , V_63 = 0 ;
char V_80 [ 11 ] ;
do {
switch ( * V_57 & 0xC0 ) {
case 0x00 :
if ( V_20 < 2 )
return - 1 ;
V_57 += 2 ;
V_63 += 2 ;
V_20 -= 2 ;
break;
case 0x40 :
if ( V_20 < 3 )
return - 1 ;
V_57 += 3 ;
V_63 += 3 ;
V_20 -= 3 ;
break;
case 0x80 :
if ( V_20 < 4 )
return - 1 ;
V_57 += 4 ;
V_63 += 4 ;
V_20 -= 4 ;
break;
case 0xC0 :
if ( V_20 < 2 )
return - 1 ;
V_61 = V_57 [ 1 ] ;
if ( V_61 < 10 || V_61 > 20 )
return - 1 ;
if ( * V_57 == V_81 ) {
memcpy ( & V_59 -> V_35 , V_57 + 7 , V_26 ) ;
memcpy ( V_80 , V_57 + 12 , V_61 - 10 ) ;
V_80 [ V_61 - 10 ] = '\0' ;
F_23 ( & V_59 -> V_82 , V_80 ) ;
}
if ( * V_57 == V_83 ) {
memcpy ( & V_59 -> V_34 , V_57 + 7 , V_26 ) ;
memcpy ( V_80 , V_57 + 12 , V_61 - 10 ) ;
V_80 [ V_61 - 10 ] = '\0' ;
F_23 ( & V_59 -> V_84 , V_80 ) ;
}
V_57 += V_61 + 2 ;
V_63 += V_61 + 2 ;
V_20 -= V_61 + 2 ;
break;
}
} while ( * V_57 != 0x00 && V_20 > 0 );
return V_63 ;
}
int F_24 ( unsigned char * V_57 , unsigned V_85 ,
struct V_58 * V_59 )
{
int V_86 , V_20 ;
V_86 = * V_57 ++ ;
if ( V_86 == 0 || ( unsigned int ) V_86 > V_85 )
return 0 ;
while ( V_86 >= 3 && * V_57 == 0x00 ) {
V_86 -- ;
V_57 ++ ;
switch ( * V_57 ) {
case V_87 :
V_20 = F_21 ( V_57 + 1 , V_59 , V_86 - 1 ) ;
break;
case V_88 :
V_20 = F_22 ( V_57 + 1 , V_59 , V_86 - 1 ) ;
break;
default:
F_18 ( V_89 L_2 , * V_57 ) ;
V_20 = 1 ;
break;
}
if ( V_20 < 0 )
return 0 ;
if ( F_25 ( V_20 >= V_86 ) )
return 0 ;
V_86 -= V_20 + 1 ;
V_57 += V_20 + 1 ;
}
return V_86 == 0 ;
}
static int F_13 ( unsigned char * V_19 , struct V_8 * V_9 )
{
unsigned char * V_57 = V_19 + 1 ;
char * V_80 ;
char V_90 [ 11 ] ;
int V_20 , V_91 ;
if ( V_9 -> rand != 0 || V_9 -> V_69 == 1 || V_9 -> V_72 == 1 ) {
* V_57 ++ = 0x00 ;
* V_57 ++ = V_87 ;
if ( V_9 -> rand != 0 ) {
* V_57 ++ = V_65 ;
* V_57 ++ = ( V_9 -> rand >> 8 ) & 0xFF ;
* V_57 ++ = ( V_9 -> rand >> 0 ) & 0xFF ;
}
if ( ( V_9 -> V_69 > 0 ) || ( V_9 -> V_72 > 0 ) ) {
int V_92 = 0 ;
* V_57 ++ = V_77 ;
* V_57 ++ = V_67 * ( V_9 -> V_69 + V_9 -> V_72 ) ;
for ( V_91 = 0 ; V_91 < V_9 -> V_69 ; V_91 ++ ) {
if ( ++ V_92 >= V_79 )
break;
memcpy ( V_57 , & V_9 -> V_68 [ V_91 ] , V_67 ) ;
V_57 [ 6 ] |= V_78 ;
V_57 += V_67 ;
}
for ( V_91 = 0 ; V_91 < V_9 -> V_72 ; V_91 ++ ) {
if ( ++ V_92 >= V_79 )
break;
memcpy ( V_57 , & V_9 -> V_71 [ V_91 ] , V_67 ) ;
V_57 [ 6 ] &= ~ V_78 ;
V_57 += V_67 ;
}
}
if ( V_9 -> V_69 > 0 ) {
* V_57 ++ = V_70 ;
* V_57 ++ = V_67 ;
memcpy ( V_57 , & V_9 -> V_68 [ 0 ] , V_67 ) ;
V_57 += V_67 ;
}
if ( V_9 -> V_72 > 0 ) {
* V_57 ++ = V_66 ;
* V_57 ++ = V_67 ;
memcpy ( V_57 , & V_9 -> V_71 [ 0 ] , V_67 ) ;
V_57 += V_67 ;
}
}
* V_57 ++ = 0x00 ;
* V_57 ++ = V_88 ;
* V_57 ++ = V_81 ;
V_80 = F_26 ( V_90 , & V_9 -> V_84 ) ;
* V_57 ++ = strlen ( V_80 ) + 10 ;
* V_57 ++ = ( strlen ( V_80 ) + 9 ) * 2 ;
* V_57 ++ = 0x47 ; * V_57 ++ = 0x00 ; * V_57 ++ = 0x11 ;
* V_57 ++ = V_26 * 2 ;
memcpy ( V_57 , & V_9 -> V_34 , V_26 ) ;
V_57 += V_26 ;
memcpy ( V_57 , V_80 , strlen ( V_80 ) ) ;
V_57 += strlen ( V_80 ) ;
* V_57 ++ = V_83 ;
V_80 = F_26 ( V_90 , & V_9 -> V_82 ) ;
* V_57 ++ = strlen ( V_80 ) + 10 ;
* V_57 ++ = ( strlen ( V_80 ) + 9 ) * 2 ;
* V_57 ++ = 0x47 ; * V_57 ++ = 0x00 ; * V_57 ++ = 0x11 ;
* V_57 ++ = V_26 * 2 ;
memcpy ( V_57 , & V_9 -> V_35 , V_26 ) ;
V_57 += V_26 ;
memcpy ( V_57 , V_80 , strlen ( V_80 ) ) ;
V_57 += strlen ( V_80 ) ;
V_20 = V_57 - V_19 ;
V_19 [ 0 ] = V_20 - 1 ;
return V_20 ;
}
void F_27 ( struct V_1 * V_2 , int V_93 , int V_36 , int V_37 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
F_1 ( V_2 ) ;
V_9 -> V_31 = 0 ;
V_9 -> V_94 = V_95 ;
if ( V_36 != - 1 )
V_9 -> V_36 = V_36 ;
if ( V_37 != - 1 )
V_9 -> V_37 = V_37 ;
V_2 -> V_96 = V_97 ;
V_2 -> V_98 = V_93 ;
V_2 -> V_99 |= V_100 ;
if ( ! F_30 ( V_2 , V_101 ) ) {
V_2 -> V_102 ( V_2 ) ;
F_31 ( V_2 , V_101 ) ;
}
}
