static inline T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 ;
V_2 = V_3 [ V_1 >> 8 ] ;
if ( V_2 )
V_2 = V_3 [ V_2 + ( V_1 & 0xff ) ] ;
else
V_2 = V_1 ;
return V_2 ;
}
int F_2 ( const struct V_4 * V_5 ,
const struct V_4 * V_6 )
{
T_1 V_7 , V_8 , V_9 , V_10 ;
const T_2 * V_11 , * V_12 ;
V_7 = F_3 ( V_5 -> V_13 ) ;
V_8 = F_3 ( V_6 -> V_13 ) ;
V_11 = V_5 -> V_14 ;
V_12 = V_6 -> V_14 ;
while ( 1 ) {
V_9 = V_10 = 0 ;
while ( V_7 && ! V_9 ) {
V_9 = F_1 ( F_3 ( * V_11 ) ) ;
V_11 ++ ;
V_7 -- ;
}
while ( V_8 && ! V_10 ) {
V_10 = F_1 ( F_3 ( * V_12 ) ) ;
V_12 ++ ;
V_8 -- ;
}
if ( V_9 != V_10 )
return ( V_9 < V_10 ) ? - 1 : 1 ;
if ( ! V_9 && ! V_10 )
return 0 ;
}
}
int F_4 ( const struct V_4 * V_5 ,
const struct V_4 * V_6 )
{
T_1 V_7 , V_8 , V_9 , V_10 ;
const T_2 * V_11 , * V_12 ;
int V_15 ;
V_7 = F_3 ( V_5 -> V_13 ) ;
V_8 = F_3 ( V_6 -> V_13 ) ;
V_11 = V_5 -> V_14 ;
V_12 = V_6 -> V_14 ;
for ( V_15 = F_5 ( V_7 , V_8 ) ; V_15 > 0 ; V_15 -- ) {
V_9 = F_3 ( * V_11 ) ;
V_10 = F_3 ( * V_12 ) ;
if ( V_9 != V_10 )
return V_9 < V_10 ? - 1 : 1 ;
V_11 ++ ;
V_12 ++ ;
}
return V_7 < V_8 ? - 1 :
V_7 > V_8 ? 1 : 0 ;
}
static T_1 * F_6 ( T_1 * V_16 , T_1 V_17 )
{
int V_18 , V_19 , V_20 ;
V_19 = 1 ;
V_20 = V_16 [ 1 ] ;
if ( ! V_20 || V_17 < V_16 [ V_19 * 2 ] || V_17 > V_16 [ V_20 * 2 ] )
return NULL ;
do {
V_18 = ( V_19 + V_20 ) / 2 ;
if ( V_17 > V_16 [ V_18 * 2 ] )
V_19 = V_18 + 1 ;
else if ( V_17 < V_16 [ V_18 * 2 ] )
V_20 = V_18 - 1 ;
else
return V_21 + V_16 [ V_18 * 2 + 1 ] ;
} while ( V_19 <= V_20 );
return NULL ;
}
int F_7 ( struct V_22 * V_23 ,
const struct V_4 * V_24 ,
char * V_25 , int * V_26 )
{
const T_2 * V_27 ;
struct V_28 * V_29 = F_8 ( V_23 ) -> V_29 ;
T_3 * V_30 ;
T_1 V_17 , V_31 , V_9 ;
T_1 * V_32 , * V_33 ;
int V_18 , V_15 , V_34 , V_35 , V_36 ;
V_30 = V_25 ;
V_27 = V_24 -> V_14 ;
V_34 = F_3 ( V_24 -> V_13 ) ;
V_15 = * V_26 ;
V_32 = NULL ;
V_36 = ! F_9 ( V_37 , & F_8 ( V_23 ) -> V_38 ) ;
while ( V_34 > 0 ) {
V_31 = F_3 ( * V_27 ++ ) ;
V_34 -- ;
if ( F_10 ( V_36 ) )
V_32 = F_6 ( V_21 , V_31 ) ;
if ( V_32 && ( V_17 = V_32 [ 0 ] ) ) {
if ( V_17 != 0xffff )
goto V_39;
if ( ! V_34 )
goto V_40;
V_9 = F_3 ( * V_27 ) - V_41 ;
if ( V_9 < V_42 ) {
V_17 = ( V_31 - V_43 ) * V_42 ;
V_17 = ( V_17 + V_9 ) * V_44 ;
V_17 += V_45 ;
V_27 ++ ;
V_34 -- ;
if ( ! V_34 )
goto V_39;
V_9 = F_3 ( * V_27 ) - V_46 ;
if ( V_9 > 0 && V_9 < V_44 ) {
V_17 += V_9 ;
V_27 ++ ;
V_34 -- ;
}
goto V_39;
}
}
while ( 1 ) {
if ( ! V_34 )
goto V_40;
V_9 = F_3 ( * V_27 ) ;
if ( F_10 ( V_36 ) )
V_32 = F_6 (
V_21 , V_9 ) ;
if ( V_32 )
break;
switch ( V_31 ) {
case 0 :
V_31 = 0x2400 ;
break;
case '/' :
V_31 = ':' ;
break;
}
V_35 = V_29 -> V_47 ( V_31 , V_30 , V_15 ) ;
if ( V_35 < 0 ) {
if ( V_35 == - V_48 )
goto V_49;
* V_30 = '?' ;
V_35 = 1 ;
}
V_30 += V_35 ;
V_15 -= V_35 ;
V_31 = V_9 ;
V_27 ++ ;
V_34 -- ;
}
V_33 = F_6 ( V_32 , V_31 ) ;
if ( V_33 ) {
V_18 = 1 ;
while ( V_18 < V_34 ) {
V_32 = F_6 ( V_33 ,
F_3 ( V_27 [ V_18 ] ) ) ;
if ( ! V_32 )
break;
V_18 ++ ;
V_33 = V_32 ;
}
if ( ( V_17 = V_33 [ 0 ] ) ) {
V_27 += V_18 ;
V_34 -= V_18 ;
goto V_39;
}
}
V_40:
switch ( V_31 ) {
case 0 :
V_17 = 0x2400 ;
break;
case '/' :
V_17 = ':' ;
break;
default:
V_17 = V_31 ;
}
V_39:
V_35 = V_29 -> V_47 ( V_17 , V_30 , V_15 ) ;
if ( V_35 < 0 ) {
if ( V_35 == - V_48 )
goto V_49;
* V_30 = '?' ;
V_35 = 1 ;
}
V_30 += V_35 ;
V_15 -= V_35 ;
}
V_35 = 0 ;
V_49:
* V_26 = ( char * ) V_30 - V_25 ;
return V_35 ;
}
static inline int F_11 ( struct V_22 * V_23 , const char * V_25 , int V_15 ,
T_4 * V_50 )
{
int V_51 = F_8 ( V_23 ) -> V_29 -> V_52 ( V_25 , V_15 , V_50 ) ;
if ( V_51 <= 0 ) {
* V_50 = '?' ;
V_51 = 1 ;
}
switch ( * V_50 ) {
case 0x2400 :
* V_50 = 0 ;
break;
case ':' :
* V_50 = '/' ;
break;
}
return V_51 ;
}
static inline T_1 * F_12 ( T_4 V_50 , int * V_51 )
{
int V_53 ;
V_53 = V_54 [ ( V_50 >> 12 ) & 0xf ] ;
if ( V_53 == 0 || V_53 == 0xffff )
return NULL ;
V_53 = V_54 [ V_53 + ( ( V_50 >> 8 ) & 0xf ) ] ;
if ( ! V_53 )
return NULL ;
V_53 = V_54 [ V_53 + ( ( V_50 >> 4 ) & 0xf ) ] ;
if ( ! V_53 )
return NULL ;
V_53 = V_54 [ V_53 + ( V_50 & 0xf ) ] ;
* V_51 = V_53 & 3 ;
if ( * V_51 == 0 )
return NULL ;
return V_54 + ( V_53 / 4 ) ;
}
int F_13 ( struct V_22 * V_23 , struct V_4 * V_24 ,
const char * V_25 , int V_15 )
{
int V_51 , V_55 , V_56 ;
T_1 * V_57 , V_58 = 0 ;
T_4 V_1 ;
V_56 = ! F_9 ( V_37 , & F_8 ( V_23 ) -> V_38 ) ;
while ( V_58 < V_59 && V_15 > 0 ) {
V_51 = F_11 ( V_23 , V_25 , V_15 , & V_1 ) ;
if ( V_56 && ( V_57 = F_12 ( V_1 , & V_55 ) ) ) {
if ( V_58 + V_55 > V_59 )
break;
do {
V_24 -> V_14 [ V_58 ++ ] = F_14 ( * V_57 ++ ) ;
} while ( -- V_55 > 0 );
} else
V_24 -> V_14 [ V_58 ++ ] = F_14 ( V_1 ) ;
V_25 += V_51 ;
V_15 -= V_51 ;
}
V_24 -> V_13 = F_14 ( V_58 ) ;
if ( V_15 > 0 )
return - V_48 ;
return 0 ;
}
int F_15 ( const struct V_60 * V_60 , const struct V_61 * V_61 ,
struct V_62 * V_63 )
{
struct V_22 * V_23 = V_60 -> V_64 ;
const char * V_25 ;
const T_1 * V_57 ;
int V_65 , V_56 , V_51 , V_15 ;
unsigned long V_66 ;
T_4 V_1 ;
T_1 V_10 ;
V_65 = F_9 ( V_67 , & F_8 ( V_23 ) -> V_38 ) ;
V_56 = ! F_9 ( V_37 , & F_8 ( V_23 ) -> V_38 ) ;
V_66 = F_16 () ;
V_25 = V_63 -> V_68 ;
V_15 = V_63 -> V_15 ;
while ( V_15 > 0 ) {
int V_69 ( V_55 ) ;
V_51 = F_11 ( V_23 , V_25 , V_15 , & V_1 ) ;
V_25 += V_51 ;
V_15 -= V_51 ;
if ( V_56 && ( V_57 = F_12 ( V_1 , & V_55 ) ) ) {
do {
V_10 = * V_57 ++ ;
if ( ! V_65 || ( V_10 = F_1 ( V_10 ) ) )
V_66 = F_17 ( V_10 , V_66 ) ;
} while ( -- V_55 > 0 );
} else {
V_10 = V_1 ;
if ( ! V_65 || ( V_10 = F_1 ( V_10 ) ) )
V_66 = F_17 ( V_10 , V_66 ) ;
}
}
V_63 -> V_66 = F_18 ( V_66 ) ;
return 0 ;
}
int F_19 ( const struct V_60 * V_70 ,
const struct V_61 * V_71 ,
const struct V_60 * V_60 , const struct V_61 * V_61 ,
unsigned int V_15 , const char * V_63 , const struct V_62 * V_68 )
{
struct V_22 * V_23 = V_70 -> V_64 ;
int V_65 , V_56 , V_51 ;
int V_72 , V_73 , V_7 , V_8 ;
const T_1 * V_74 , * V_75 ;
const char * V_76 , * V_77 ;
T_1 V_9 , V_10 ;
T_4 V_1 ;
V_65 = F_9 ( V_67 , & F_8 ( V_23 ) -> V_38 ) ;
V_56 = ! F_9 ( V_37 , & F_8 ( V_23 ) -> V_38 ) ;
V_76 = V_63 ;
V_7 = V_15 ;
V_77 = V_68 -> V_68 ;
V_8 = V_68 -> V_15 ;
V_72 = V_73 = 0 ;
V_74 = V_75 = NULL ;
while ( V_7 > 0 && V_8 > 0 ) {
if ( ! V_72 ) {
V_51 = F_11 ( V_23 , V_76 , V_7 , & V_1 ) ;
V_76 += V_51 ;
V_7 -= V_51 ;
if ( V_56 )
V_74 = F_12 ( V_1 , & V_72 ) ;
if ( ! V_56 || ! V_74 ) {
V_9 = V_1 ;
V_74 = & V_9 ;
V_72 = 1 ;
}
}
if ( ! V_73 ) {
V_51 = F_11 ( V_23 , V_77 , V_8 , & V_1 ) ;
V_77 += V_51 ;
V_8 -= V_51 ;
if ( V_56 )
V_75 = F_12 ( V_1 , & V_73 ) ;
if ( ! V_56 || ! V_75 ) {
V_10 = V_1 ;
V_75 = & V_10 ;
V_73 = 1 ;
}
}
V_9 = * V_74 ;
V_10 = * V_75 ;
if ( V_65 ) {
if ( ! ( V_9 = F_1 ( V_9 ) ) ) {
V_74 ++ ;
V_72 -- ;
continue;
}
if ( ! ( V_10 = F_1 ( V_10 ) ) ) {
V_75 ++ ;
V_73 -- ;
continue;
}
}
if ( V_9 < V_10 )
return - 1 ;
else if ( V_9 > V_10 )
return 1 ;
V_74 ++ ;
V_72 -- ;
V_75 ++ ;
V_73 -- ;
}
if ( V_7 < V_8 )
return - 1 ;
if ( V_7 > V_8 )
return 1 ;
return 0 ;
}
