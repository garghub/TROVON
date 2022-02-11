int F_1 ( const char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 , int V_5 ,
const T_1 * V_6 , int V_7 , unsigned char * V_8 )
{
unsigned char V_9 [ V_10 ] , * V_11 , V_12 [ 4 ] ;
int V_13 , V_14 , V_15 , V_16 , V_17 ;
unsigned long V_18 = 1 ;
T_2 V_19 , V_20 ;
V_17 = F_2 ( V_6 ) ;
if ( V_17 < 0 )
return 0 ;
F_3 ( & V_19 ) ;
V_11 = V_8 ;
V_16 = V_7 ;
if ( ! V_1 )
V_2 = 0 ;
else if ( V_2 == - 1 )
V_2 = strlen ( V_1 ) ;
if ( ! F_4 ( & V_19 , V_1 , V_2 , V_6 , NULL ) ) {
F_5 ( & V_19 ) ;
return 0 ;
}
while ( V_16 ) {
if ( V_16 > V_17 )
V_13 = V_17 ;
else
V_13 = V_16 ;
V_12 [ 0 ] = ( unsigned char ) ( ( V_18 >> 24 ) & 0xff ) ;
V_12 [ 1 ] = ( unsigned char ) ( ( V_18 >> 16 ) & 0xff ) ;
V_12 [ 2 ] = ( unsigned char ) ( ( V_18 >> 8 ) & 0xff ) ;
V_12 [ 3 ] = ( unsigned char ) ( V_18 & 0xff ) ;
if ( ! F_6 ( & V_20 , & V_19 ) ) {
F_5 ( & V_19 ) ;
return 0 ;
}
if ( ! F_7 ( & V_20 , V_3 , V_4 )
|| ! F_7 ( & V_20 , V_12 , 4 )
|| ! F_8 ( & V_20 , V_9 , NULL ) ) {
F_5 ( & V_19 ) ;
F_5 ( & V_20 ) ;
return 0 ;
}
F_5 ( & V_20 ) ;
memcpy ( V_11 , V_9 , V_13 ) ;
for ( V_14 = 1 ; V_14 < V_5 ; V_14 ++ ) {
if ( ! F_6 ( & V_20 , & V_19 ) ) {
F_5 ( & V_19 ) ;
return 0 ;
}
if ( ! F_7 ( & V_20 , V_9 , V_17 )
|| ! F_8 ( & V_20 , V_9 , NULL ) ) {
F_5 ( & V_19 ) ;
F_5 ( & V_20 ) ;
return 0 ;
}
F_5 ( & V_20 ) ;
for ( V_15 = 0 ; V_15 < V_13 ; V_15 ++ )
V_11 [ V_15 ] ^= V_9 [ V_15 ] ;
}
V_16 -= V_13 ;
V_18 ++ ;
V_11 += V_13 ;
}
F_5 ( & V_19 ) ;
# ifdef F_9
fprintf ( V_21 , L_1 ) ;
F_10 ( V_1 , V_2 ) ;
fprintf ( V_21 , L_2 ) ;
F_10 ( V_3 , V_4 ) ;
fprintf ( V_21 , L_3 , V_5 ) ;
fprintf ( V_21 , L_4 ) ;
F_10 ( V_8 , V_7 ) ;
# endif
return 1 ;
}
int F_11 ( const char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 , int V_5 ,
int V_7 , unsigned char * V_8 )
{
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , F_12 () ,
V_7 , V_8 ) ;
}
main ()
{
unsigned char V_8 [ 4 ] ;
unsigned char V_3 [] = { 0x12 , 0x34 , 0x56 , 0x78 } ;
F_11 ( L_5 , - 1 , V_3 , 4 , 5 , 4 , V_8 ) ;
fprintf ( V_21 , L_6 ,
V_8 [ 0 ] , V_8 [ 1 ] , V_8 [ 2 ] , V_8 [ 3 ] ) ;
}
int F_13 ( T_3 * V_22 , const char * V_1 , int V_2 ,
T_4 * V_23 , const T_5 * V_24 ,
const T_1 * V_25 , int V_26 )
{
const unsigned char * V_27 ;
int V_28 ;
T_6 * V_29 = NULL ;
const T_5 * V_30 ;
int V_31 = 0 ;
if ( V_23 == NULL || V_23 -> type != V_32 ||
V_23 -> V_33 . V_34 == NULL ) {
F_14 ( V_35 , V_36 ) ;
goto V_37;
}
V_27 = V_23 -> V_33 . V_34 -> V_38 ;
V_28 = V_23 -> V_33 . V_34 -> V_39 ;
if ( ! ( V_29 = F_15 ( NULL , & V_27 , V_28 ) ) ) {
F_14 ( V_35 , V_36 ) ;
goto V_37;
}
if ( F_16 ( V_29 -> V_40 -> V_41 ) != V_42 ) {
F_14 ( V_35 ,
V_43 ) ;
goto V_37;
}
V_30 = F_17 ( V_29 -> V_44 -> V_41 ) ;
if ( ! V_30 ) {
F_14 ( V_35 , V_45 ) ;
goto V_37;
}
if ( ! F_18 ( V_22 , V_30 , NULL , NULL , NULL , V_26 ) )
goto V_37;
if ( F_19 ( V_22 , V_29 -> V_44 -> V_46 ) < 0 ) {
F_14 ( V_35 , V_47 ) ;
goto V_37;
}
V_31 = F_20 ( V_22 , V_1 , V_2 ,
V_29 -> V_40 -> V_46 , V_24 , V_25 , V_26 ) ;
V_37:
F_21 ( V_29 ) ;
return V_31 ;
}
int F_20 ( T_3 * V_22 , const char * V_1 ,
int V_2 , T_4 * V_23 ,
const T_5 * V_24 , const T_1 * V_25 , int V_26 )
{
unsigned char * V_3 , V_48 [ V_49 ] ;
const unsigned char * V_27 ;
int V_4 , V_5 , V_28 ;
int V_31 = 0 ;
unsigned int V_7 = 0 ;
int V_50 , V_51 ;
T_7 * V_52 = NULL ;
const T_1 * V_53 ;
if ( F_22 ( V_22 ) == NULL ) {
F_14 ( V_54 , V_55 ) ;
goto V_37;
}
V_7 = F_23 ( V_22 ) ;
F_24 ( V_7 <= sizeof V_48 ) ;
if ( ! V_23 || ( V_23 -> type != V_32 ) ) {
F_14 ( V_54 , V_36 ) ;
goto V_37;
}
V_27 = V_23 -> V_33 . V_34 -> V_38 ;
V_28 = V_23 -> V_33 . V_34 -> V_39 ;
if ( ! ( V_52 = F_25 ( NULL , & V_27 , V_28 ) ) ) {
F_14 ( V_54 , V_36 ) ;
goto V_37;
}
V_7 = F_23 ( V_22 ) ;
if ( V_52 -> V_56 && ( F_26 ( V_52 -> V_56 ) != ( int ) V_7 ) ) {
F_14 ( V_54 , V_57 ) ;
goto V_37;
}
if ( V_52 -> V_58 )
V_50 = F_16 ( V_52 -> V_58 -> V_41 ) ;
else
V_50 = V_59 ;
if ( ! F_27 ( V_60 , V_50 , NULL , & V_51 , 0 ) ) {
F_14 ( V_54 , V_61 ) ;
goto V_37;
}
V_53 = F_28 ( V_51 ) ;
if ( V_53 == NULL ) {
F_14 ( V_54 , V_61 ) ;
goto V_37;
}
if ( V_52 -> V_3 -> type != V_62 ) {
F_14 ( V_54 , V_63 ) ;
goto V_37;
}
V_3 = V_52 -> V_3 -> V_33 . V_64 -> V_38 ;
V_4 = V_52 -> V_3 -> V_33 . V_64 -> V_39 ;
V_5 = F_26 ( V_52 -> V_5 ) ;
if ( ! F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_53 ,
V_7 , V_48 ) )
goto V_37;
V_31 = F_18 ( V_22 , NULL , NULL , V_48 , NULL , V_26 ) ;
V_37:
F_29 ( V_48 , V_7 ) ;
F_30 ( V_52 ) ;
return V_31 ;
}
static void F_10 ( const unsigned char * V_11 , int V_65 )
{
for (; V_65 -- ; V_11 ++ )
fprintf ( V_21 , L_7 , * V_11 ) ;
fprintf ( V_21 , L_8 ) ;
}
