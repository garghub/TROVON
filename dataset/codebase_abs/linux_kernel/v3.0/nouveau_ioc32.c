long F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned long V_4 )
{
unsigned int V_5 = F_2 ( V_3 ) ;
T_1 * V_6 = NULL ;
int V_7 ;
if ( V_5 < V_8 )
return F_3 ( V_2 , V_3 , V_4 ) ;
#if 0
if (nr < DRM_COMMAND_BASE + DRM_ARRAY_SIZE(mga_compat_ioctls))
fn = nouveau_compat_ioctls[nr - DRM_COMMAND_BASE];
#endif
if ( V_6 != NULL )
V_7 = (* V_6)( V_2 , V_3 , V_4 ) ;
else
V_7 = F_4 ( V_2 , V_3 , V_4 ) ;
return V_7 ;
}
